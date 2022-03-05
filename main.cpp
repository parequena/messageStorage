#include <RenderManager.hpp>
#include <MessageManager.hpp>

int main(int, const char *[])
{
	// Manages the render.
	RenderManager renderMgr{};
	// Manages all.
	MessageManager manager{renderMgr};
	manager.processInput();

	return 0;
}
