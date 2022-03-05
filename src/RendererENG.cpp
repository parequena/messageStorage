#include <RendererENG.hpp>

#include <iostream>

// Draws UI.
void RendererENG::drawMenu() const noexcept
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
void RendererENG::askForName() const noexcept
{
    std::cout << k_askName << '\n';
}

void RendererENG::errorUserExist() const noexcept
{
    std::cerr << k_errUserEx << '\n';
}

void RendererENG::addUser(std::string_view user) const noexcept
{
    std::cout << k_user << user << k_added << '\n';
}

void RendererENG::askFrom() const noexcept
{
    std::cout << k_from << '\n';
}

void RendererENG::askFromUser(std::string_view user) const noexcept
{
    std::cout << k_from << user << '\n';
}

void RendererENG::errorUserNOTExist() const noexcept
{
    std::cerr << k_errUserNOTEx << '\n';
}

void RendererENG::askTo() const noexcept
{
    std::cout << k_to << '\n';
}

void RendererENG::askMessage() const noexcept
{
    std::cout << k_message << '\n';
}

void RendererENG::askMessageSent() const noexcept
{
    std::cout << k_messageSent << '\n';
}

void RendererENG::askForNameUser() const noexcept
{
    std::cout << k_nameUser << '\n';
}

void RendererENG::askBeginMessages() const noexcept
{
    std::cout << k_begMessages << '\n';
}

void RendererENG::askNumberMessage(int nMess) const noexcept
{
    std::cout << k_message << std::to_string(nMess) << '\n';
}

void RendererENG::askContent() const noexcept
{
    std::cout << k_content << '\n';
}

void RendererENG::askContentUser(std::string_view user) const noexcept
{
    std::cout << k_content << user << '\n';
}

void RendererENG::askEndMessages() const noexcept
{
    std::cout << k_endMessages << '\n';
}

void RendererENG::askQuit() const noexcept
{
    std::cout << k_quit << '\n';
}

void RendererENG::errorInvalidOpt() const noexcept
{
    std::cerr << k_errInvOpt << '\n';
}

void RendererENG::askWait4Key() const noexcept
{
    std::cout << k_wait4Key << '\n';
}