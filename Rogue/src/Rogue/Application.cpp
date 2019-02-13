#include "Application.h"

#include "Rogue/Event/ApplicationEvent.h"
#include "Rogue/Log.h"
namespace Rogue {


	Application::Application()
	{
	}


	Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		RG_TRACE(e);
		while (true);
	}
}
