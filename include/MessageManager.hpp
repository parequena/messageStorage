#ifndef MESSAGE_MANAGER_HPP
#define MESSAGE_MANAGER_HPP

#include <unordered_map>
#include <vector>
#include <string>
#include <string_view>
#include <array>
#include <iostream>

struct RenderManager;

struct MessageManager
{
    // Ctor.
    explicit MessageManager(RenderManager &renderer) noexcept;

    // process Input.
    [[maybe_unused]] bool processInput();

private:
    // Renderer
    RenderManager &m_renderer;

    template <typename func_t>
    std::string askForUser(func_t func)
    {
        (m_renderer.*func)();
        std::string user{};
        std::getline(std::cin, user);

        return exists(user) ? user : std::string{};
    }

    // exit?
    bool m_exit{false};

    // Exists an user.
    [[nodiscard]] bool exists(std::string_view user) const noexcept;

    // AddUser
    void addUser() noexcept;

    // Send message.
    void sendMessage() noexcept;

    // Recieve all messages for user.
    void receiveAllMessages() noexcept;

    // Change lang.
    void changeLang() noexcept;

    // Quit.
    void quit() noexcept;

    struct menuToMeth
    {
        int val{};
        void (MessageManager::*pMeth)() noexcept {};
        // This signature could be const noexcept if we move this code to an other scope.
        // Unordered map into a component storage, and message manager, as component manager.
        // This way, we could have that componen storage pased as reference to this class.
    };

    inline static std::array k_menuToMethod{
        menuToMeth{1, &MessageManager::addUser},
        menuToMeth{2, &MessageManager::sendMessage},
        menuToMeth{3, &MessageManager::receiveAllMessages},
        menuToMeth{4, &MessageManager::changeLang},
        menuToMeth{5, &MessageManager::quit}};

    // --------------------------------------
    // Component storage. This could be moved outside.
    struct Message
    {
        std::string from{};
        std::string content{};
    };

    // Messages.
    std::unordered_map<std::string, std::vector<Message>>
        m_messages{};
};

#endif /* MESSAGE_MANAGER_HPP */
