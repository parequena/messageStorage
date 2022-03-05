#include <MessageManager.hpp>
#include <RenderManager.hpp>
#include <MessageStorage.hpp>

// Ctor.
MessageManager::MessageManager(RenderManager &renderer, MessageStorage &storage) noexcept
    : m_renderer{renderer}, m_storage{storage}
{
}

// process Input.
bool MessageManager::processInput()
{
    auto wait4Key = [&]()
    {
        m_renderer.askWait4Key();
        std::string aux{};
        std::getline(std::cin, aux);
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

        MenuOptions opt{static_cast<MenuOptions>(value)};

        if (opt == MenuOptions::EXIT)
        {
            m_renderer.askQuit();
            m_exit = false;
            m_storage.clearAll();
            break;
        }

        for (auto const &v : k_menuToMethod)
        {
            if (v.val != opt)
            {
                continue;
            }

            (this->*v.pMeth)();
            wait4Key();
            break;
        }
    }

    return m_exit;
}

// AddUser
void MessageManager::addUser() const noexcept
{
    m_renderer.askForName();
    std::string user{};
    std::getline(std::cin, user);

    if (!m_storage.existUser(user)) // This can be changed with exists(user);
    {
        m_renderer.errorUserExist();
        return;
    }

    m_storage.addUser(user);
    m_renderer.addUser(user);
}

// Send message.
void MessageManager::sendMessage() const noexcept
{
    // Who sended the message.
    std::string from = askForUser(&RenderManager::askFrom);
    if (from.empty())
    {
        m_renderer.errorUserNOTExist();
        return;
    }

    // Who recived the message.
    std::string to = askForUser(&RenderManager::askTo);
    if (to.empty())
    {
        m_renderer.errorUserNOTExist();
        return;
    }

    // Ask message.
    m_renderer.askMessage();
    std::string msg{};
    std::getline(std::cin, msg);
    m_renderer.askMessageSent();

    m_storage.addMessage(to, from, msg);
}

// Recieve all messages for user.
void MessageManager::receiveAllMessages() const noexcept
{
    std::string user = askForUser(&RenderManager::askForNameUser);
    if (user.empty())
    {
        m_renderer.errorUserNOTExist();
        return;
    }

    m_renderer.askBeginMessages();
    auto nMess{0};

    auto const &messages = m_storage.getMessages(user);
    for (auto const &msg : messages)
    {
        ++nMess;
        m_renderer.askNumberMessage(nMess);
        m_renderer.askFromUser(msg.from);
        m_renderer.askContentUser(msg.content);
    }

    m_storage.clearUser(user);
    m_renderer.askEndMessages();
}

// Change lang.
void MessageManager::changeLang() const noexcept
{
    // Implement logic to swap language.
    m_renderer.swapRenderer();
}