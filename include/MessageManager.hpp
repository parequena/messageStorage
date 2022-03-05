#ifndef MESSAGE_STORAGE_HPP
#define MESSAGE_STORAGE_HPP

#include <unordered_map>
#include <string>
#include <vector>
#include <string_view>

struct MessageManager
{
    struct Message
    {
        std::string from{};
        std::string content{};
    };

    [[nodiscard]] bool existUser(std::string_view user) const noexcept;
    void addUser(std::string_view user) noexcept;
    void addMessage(std::string_view user, std::string_view from, std::string_view msg) noexcept;
    [[nodiscard]] std::vector<Message> getMessages(std::string_view user) const noexcept;
    void clearUser(std::string_view user) noexcept;
    void clearAll() noexcept;

private:
    // Messages.
    std::unordered_map<std::string, std::vector<Message>>
        m_messages{};
};

#endif /* MESSAGE_STORAGE_HPP */
