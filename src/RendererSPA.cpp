#include <RendererSPA.hpp>

#include <iostream>

// Draws UI.
void RendererSPA::drawMenu() const noexcept
{
    // This could be moved into parent class, but I wan't to keep clean the interface,
    // because, if we use SDL2 to provide UI we don't really need <iostream>
    for (int i{}; i < 80; ++i)
    {
        std::cout << '\n';
    }

    std::cout << k_rawMenu;
}

// Draws name
void RendererSPA::askForName() const noexcept
{
    std::cout << k_askName << '\n';
}

void RendererSPA::errorUserExist() const noexcept
{
    std::cerr << k_errUserEx << '\n';
}

void RendererSPA::addUser(std::string_view user) const noexcept
{
    std::cout << k_user << user << k_added << '\n';
}

void RendererSPA::askFrom() const noexcept
{
    std::cout << k_from << '\n';
}

void RendererSPA::askFromUser(std::string_view user) const noexcept
{
    std::cout << k_from << user << '\n';
}

void RendererSPA::errorUserNOTExist() const noexcept
{
    std::cerr << k_errUserNOTEx << '\n';
}

void RendererSPA::askTo() const noexcept
{
    std::cout << k_to << '\n';
}

void RendererSPA::askMessage() const noexcept
{
    std::cout << k_message << '\n';
}

void RendererSPA::askMessageSent() const noexcept
{
    std::cout << k_messageSent << '\n';
}

void RendererSPA::askForNameUser() const noexcept
{
    std::cout << k_nameUser << '\n';
}

void RendererSPA::askBeginMessages() const noexcept
{
    std::cout << k_begMessages << '\n';
}

void RendererSPA::askNumberMessage(int nMess) const noexcept
{
    std::cout << k_message << std::to_string(nMess) << '\n';
}

void RendererSPA::askContent() const noexcept
{
    std::cout << k_content << '\n';
}

void RendererSPA::askContentUser(std::string_view user) const noexcept
{
    std::cout << k_content << user << '\n';
}

void RendererSPA::askEndMessages() const noexcept
{
    std::cout << k_endMessages << '\n';
}

void RendererSPA::askQuit() const noexcept
{
    std::cout << k_quit << '\n';
}

void RendererSPA::errorInvalidOpt() const noexcept
{
    std::cerr << k_errInvOpt << '\n';
}

void RendererSPA::askWait4Key() const noexcept
{
    std::cout << k_wait4Key << '\n';
}