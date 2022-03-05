#include <RenderManager.hpp>
#include <MessageManager.hpp>
#include <MessageStorage.hpp>

int main(int, const char *[])
{
	// Storages the messages.
	MessageStorage msgStr{};

	// Manages the render.
	RenderManager renderMgr{};

	// Manages all.
	MessageManager manager{renderMgr, msgStr};
	manager.processInput();

	return 0;
}
