#pragma once

#include "rgpch.h"

#include "Rogue/Core.h"
#include "Rogue/Events/Event.h"


namespace Rogue {


	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Rogue Engine",
				unsigned int width = 1280,
				unsigned int height = 720 )
			: Title(title), Width(width), Height(height){}

	};

	class ROGUE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window(){}
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;


		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}