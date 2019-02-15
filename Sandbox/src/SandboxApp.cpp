#include <Rogue.h>

class ExampleLayer : public Rogue::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		//RG_INFO("ExampleLayer::Update");
	}

	void OnEvent(Rogue::Event& event) override
	{
		RG_TRACE("{0}", event);
	}

};


class Sandbox : public Rogue::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Rogue::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Rogue::Application* Rogue::CreateApplication()
{
	return new Sandbox();
}