#include <MessageManager.hpp>
#include <RenderManager.hpp>

// Ctor.
MessageManager::MessageManager(RenderManager &renderer) noexcept
    : m_renderer{renderer}
{
}

// process Input.
bool MessageManager::processInput()
{
    auto wait4Key = [&]()
    {
        m_renderer.askWait4Key();
        std::cin.get();
    };

    while (!m_exit)
    {
        m_renderer.drawMenu();
        std::string input{};
        std::getline(std::cin, input);
        int value = std::atoi(input.data());

        if (value == 0)
        {
            m_renderer.errorInvalidOpt();
            wait4Key();
            continue;
        }

        for (auto const &v : k_menuToMethod)
        {
            if (v.val == value)
            {
                (this->*v.pMeth)();
                wait4Key();
                break;
            }
        }
    }

    return m_exit;
}

// Exists an user.
bool MessageManager::exists(std::string_view user) const noexcept
{
    auto const search = m_messages.find(user.data());
    if (search == m_messages.end())
    {
        m_renderer.errorUserNOTExist();
        return false;
    }

    return true;
}

// AddUser
void MessageManager::addUser() noexcept
{
    m_renderer.askForName();
    std::string user{};
    std::getline(std::cin, user);

    auto [pair, inserted] = m_messages.try_emplace(user, std::vector<Message>());
    if (!inserted) // This can be changed with exists(user);
    {
        m_renderer.errorUserExist();
        return;
    }

    m_renderer.addUser(user);

    // Precatching messages.
    // This can ve avoided, but it could be slower.
    pair->second.reserve(10);
}

// Send message.
void MessageManager::sendMessage() noexcept
{
    // Who sended the message.
    std::string from = askForUser(&RenderManager::askFrom);
    if (from.empty())
    {
        return;
    }

    // Who recived the message.
    std::string to = askForUser(&RenderManager::askTo);
    if (to.empty())
    {
        return;
    }

    // Ask message.
    m_renderer.askMessage();
    std::string msg{};
    std::getline(std::cin, msg);
    m_renderer.askMessageSent();

    m_messages[to].emplace_back(Message{from, msg});
}

// Recieve all messages for user.
void MessageManager::receiveAllMessages() noexcept
{
    std::string user = askForUser(&RenderManager::askForNameUser);
    if (user.empty())
    {
        return;
    }

    m_renderer.askBeginMessages();
    auto nMess{0};

    auto &messages = m_messages.at(user);
    for (auto const &msg : messages)
    {
        ++nMess;
        m_renderer.askNumberMessage(nMess);
        m_renderer.askFromUser(msg.from);
        m_renderer.askContentUser(msg.content);
    }

    messages.clear();
    m_renderer.askEndMessages();
}

// Change lang.
void MessageManager::changeLang() noexcept
{
    // Implement logic to swap language.
    m_renderer.swapRenderer();
}

// Quit.
void MessageManager::quit() noexcept
{
    m_exit = true;
}