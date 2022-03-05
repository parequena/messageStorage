#include <RenderManager.hpp>
#include <InputManager.hpp>
#include <MessageManager.hpp>

int main(int, const char *[])
{
	// Storages the messages.
	MessageManager msgStr{};

	// Manages the render.
	RenderManager renderMgr{};

	// Manages all.
	InputManager manager{renderMgr, msgStr};
	manager.processInput();

	return 0;
}
