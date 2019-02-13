#pragma once

#include "Core.h"
#include "Event/Event.h"

namespace Rogue {

	class ROGUE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}

