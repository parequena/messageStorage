#include <RenderManager.hpp>

#include <RendererSPA.hpp>

// Swap renderer.
void RenderManager::swapRenderer() noexcept
{
    switch (m_renderType)
    {
    case RenderTypes::ENG:
        m_renderer.reset(nullptr);
        m_renderer = std::make_unique<RendererSPA>();
        m_renderType = RenderTypes::SPA;
        break;

    default: // Default to eng.
        m_renderer.reset(nullptr);
        m_renderer = std::make_unique<RendererENG>();
        m_renderType = RenderTypes::ENG;
        break;
    }
}