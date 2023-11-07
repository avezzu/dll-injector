#include "mem/mem.h"
#include "gui/gui.h"
#include <thread>


INT APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{

    
    mem::GetProcID();
    // create gui
	gui::CreateHWindow("Cheat Menu");
	gui::CreateDevice();
	gui::CreateImGui();

	while (gui::isRunning)
	{
		gui::BeginRender();
		gui::Render();
		gui::EndRender();

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}

	// destroy gui
	gui::DestroyImGui();
	gui::DestroyDevice();
	gui::DestroyHWindow();

	return EXIT_SUCCESS;
}
