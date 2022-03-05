#include <MessageManager.hpp>

bool MessageManager::existUser(std::string_view user) const noexcept
{
    return (m_messages.find(user.data()) == m_messages.end());
}

void MessageManager::addUser(std::string_view user) noexcept
{
    auto [pair, inserted] = m_messages.try_emplace(user.data(), std::vector<Message>());
    if (!inserted) // This can be changed with exists(user);
    {
        return;
    }

    // Precatching messages.
    // This can ve avoided, but it could be slower.
    pair->second.reserve(10);
}

void MessageManager::addMessage(std::string_view user, std::string_view from, std::string_view msg) noexcept
{
    if (!existUser(user))
    {
        // This should not happen, user has been previously checked.
        return;
    }

    m_messages[user.data()].emplace_back(Message{from.data(), msg.data()});
}

std::vector<MessageManager::Message> MessageManager::getMessages(std::string_view user) const noexcept
{
    if (!existUser(user))
    {
        // This should not happen, user has been previously checked.
        return {};
    }

    return m_messages.at(user.data());
}

void MessageManager::clearUser(std::string_view user) noexcept
{
    if (!existUser(user))
    {
        // This should not happen, user has been previously checked.
        return;
    }

    m_messages.at(user.data()).clear();
}

void MessageManager::clearAll() noexcept
{
    for (auto [u, m] : m_messages)
    {
        m.clear();
    }

    m_messages.clear();
}