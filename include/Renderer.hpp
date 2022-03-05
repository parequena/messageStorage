#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <string_view>

struct Renderer
{
    // Dtor.
    virtual ~Renderer() noexcept = default;

    virtual void drawMenu() const noexcept = 0;
    virtual void askForName() const noexcept = 0;
    virtual void errorUserExist() const noexcept = 0;
    virtual void addUser(std::string_view user) const noexcept = 0;
    virtual void askFrom() const noexcept = 0;
    virtual void askFromUser(std::string_view user) const noexcept = 0;
    virtual void errorUserNOTExist() const noexcept = 0;
    virtual void askTo() const noexcept = 0;
    virtual void askMessage() const noexcept = 0;
    virtual void askMessageSent() const noexcept = 0;
    virtual void askForNameUser() const noexcept = 0;
    virtual void askBeginMessages() const noexcept = 0;
    virtual void askNumberMessage(int nMess) const noexcept = 0;
    virtual void askContent() const noexcept = 0;
    virtual void askContentUser(std::string_view user) const noexcept = 0;
    virtual void askEndMessages() const noexcept = 0;
    virtual void askQuit() const noexcept = 0;
    virtual void errorInvalidOpt() const noexcept = 0;
    virtual void askWait4Key() const noexcept = 0;
};

#endif /* RENDERER_HPP */
