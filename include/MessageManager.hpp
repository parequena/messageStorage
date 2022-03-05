#ifndef MESSAGE_MANAGER_HPP
#define MESSAGE_MANAGER_HPP

#include <unordered_map>
#include <vector>
#include <string>
#include <string_view>
#include <array>
#include <iostream> // std::cin

struct RenderManager;
// struct MessageStorage;
#include <MessageStorage.hpp>

struct MessageManager
{
    // Ctor.
    explicit MessageManager(RenderManager &renderer, MessageStorage &storage) noexcept;

    // process Input.
    [[maybe_unused]] bool processInput();

private:
    // Renderer
    RenderManager &m_renderer;

    // Component
    MessageStorage &m_storage;

    template <typename func_t>
    std::string askForUser(func_t func) const noexcept
    {
        (m_renderer.*func)();
        std::string user{};
        std::getline(std::cin, user);

        return m_storage.existUser(user) ? user : std::string{};
    }

    // exit?
    bool m_exit{false};

    // AddUser
    void addUser() const noexcept;

    // Send message.
    void sendMessage() const noexcept;

    // Recieve all messages for user.
    void receiveAllMessages() const noexcept;

    // Change lang.
    void changeLang() const noexcept;

    enum class MenuOptions : std::uint8_t
    {
        ADD_USER = 1,
        SEND_MESSAGE = 2,
        RECIEVE_MSG = 3,
        CHANGE_LANG = 4,
        EXIT = 5
    };

    struct menuToMeth
    {
        MenuOptions val{MenuOptions::EXIT};
        void (MessageManager::*pMeth)() const noexcept {};
        // This signature could be const noexcept if we move this code to an other scope.
        // Unordered map into a component storage, and message manager, as component manager.
        // This way, we could have that componen storage pased as reference to this class.
    };

    inline static std::array k_menuToMethod{
        menuToMeth{MenuOptions::ADD_USER, &MessageManager::addUser},
        menuToMeth{MenuOptions::SEND_MESSAGE, &MessageManager::sendMessage},
        menuToMeth{MenuOptions::RECIEVE_MSG, &MessageManager::receiveAllMessages},
        menuToMeth{MenuOptions::CHANGE_LANG, &MessageManager::changeLang}};
};

#endif /* MESSAGE_MANAGER_HPP */
