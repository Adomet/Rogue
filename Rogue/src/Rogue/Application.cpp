#include "Application.h"

#include "Rogue/Events/ApplicationEvent.h"
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
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			RG_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			RG_TRACE(e);
		}

		while (true);
	}

}