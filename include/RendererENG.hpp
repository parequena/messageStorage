#ifndef RENDERER_ENG_HPP
#define RENDERER_ENG_HPP

#include "Renderer.hpp"
#include <iostream>

struct RendererENG final : Renderer
{
    void drawMenu() const noexcept final;
    void askForName() const noexcept final;
    void errorUserExist() const noexcept final;
    void addUser(std::string_view user) const noexcept final;
    void askFrom() const noexcept final;
    void askFromUser(std::string_view user) const noexcept final;
    void errorUserNOTExist() const noexcept final;
    void askTo() const noexcept final;
    void askMessage() const noexcept final;
    void askMessageSent() const noexcept final;
    void askForNameUser() const noexcept final;
    void askBeginMessages() const noexcept final;
    void askNumberMessage(int nMess) const noexcept final;
    void askContent() const noexcept final;
    void askContentUser(std::string_view user) const noexcept final;
    void askEndMessages() const noexcept final;
    void askQuit() const noexcept final;
    void errorInvalidOpt() const noexcept final;
    void askWait4Key() const noexcept final;

private:
    // ALL IN STATIC TO DUPLICATE TO SPANISH EASY AND FAST.
    inline static constexpr auto k_rawMenu{R"(Please select an option:
    1. Create User
    2. Send Message
    3. Recieve all messages for user
    4. Change language
    5. Quit
)"};

    inline static constexpr auto k_askName{"Please enter a name:"};
    inline static constexpr auto k_errUserEx{"ERROR: User already exists!"};
    inline static constexpr auto k_user{"User "};
    inline static constexpr auto k_added{" added!"};
    inline static constexpr auto k_from{"From: "};
    inline static constexpr auto k_errUserNOTEx{"ERROR: User doen't exists!"};
    inline static constexpr auto k_to{"To: "};
    inline static constexpr auto k_message{"Message: "};
    inline static constexpr auto k_messageSent{"Message Sent!"};
    inline static constexpr auto k_nameUser{"Enter name of user to receive all messages for: "};
    inline static constexpr auto k_begMessages{"===== BEGIN MESSAGES ====="};
    inline static constexpr auto k_content{"Content: "};
    inline static constexpr auto k_endMessages{"===== END MESSAGES ====="};
    inline static constexpr auto k_quit{"Quitting!"};
    inline static constexpr auto k_errInvOpt{"Invalid Option Selected"};
    inline static constexpr auto k_wait4Key{"Enter any key and press return to continue....."};
};

#endif /* RENDERER_ENG_HPP */
