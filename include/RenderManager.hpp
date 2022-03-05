#ifndef RENDER_MANAGER_HPP
#define RENDER_MANAGER_HPP

#include <memory>
#include <cstdint>

#include "RendererENG.hpp"

struct RenderManager
{
    inline void drawMenu() const noexcept { m_renderer->drawMenu(); }
    inline void askForName() const noexcept { m_renderer->askForName(); }
    inline void errorUserExist() const noexcept { m_renderer->errorUserExist(); }
    inline void addUser(std::string_view user) const noexcept { m_renderer->addUser(user); }
    inline void askFrom() const noexcept { m_renderer->askFrom(); }
    inline void askFromUser(std::string_view user) const noexcept { m_renderer->askFromUser(user); }
    inline void errorUserNOTExist() const noexcept { m_renderer->errorUserNOTExist(); }
    inline void askTo() const noexcept { m_renderer->askTo(); }
    inline void askMessage() const noexcept { m_renderer->askMessage(); }
    inline void askMessageSent() const noexcept { m_renderer->askMessageSent(); }
    inline void askForNameUser() const noexcept { m_renderer->askForNameUser(); }
    inline void askBeginMessages() const noexcept { m_renderer->askBeginMessages(); }
    inline void askNumberMessage(int nMess) const noexcept { m_renderer->askNumberMessage(nMess); }
    inline void askContent() const noexcept { m_renderer->askContent(); }
    inline void askContentUser(std::string_view user) const noexcept { m_renderer->askContentUser(user); }
    inline void askEndMessages() const noexcept { m_renderer->askEndMessages(); }
    inline void askQuit() const noexcept { m_renderer->askQuit(); }
    inline void errorInvalidOpt() const noexcept { m_renderer->errorInvalidOpt(); }
    inline void askWait4Key() const noexcept { m_renderer->askWait4Key(); }

    // Swap renderer.
    void swapRenderer() noexcept;

private:
    enum class RenderTypes : std::int8_t
    {
        ENG,
        SPA,
        ERROR = -1
    } m_renderType{};

    // pimpl idiom!!
    std::unique_ptr<Renderer> m_renderer{std::make_unique<RendererENG>()};
};

#endif /* RENDER_MANAGER_HPP */
