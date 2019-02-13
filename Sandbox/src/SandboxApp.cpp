#include <Rogue.h>

class Sandbox : public Rogue::Application
{
public :
	Sandbox()
	{
		
	}
	~Sandbox()
	{

	}
};

Rogue::Application* Rogue::CreateApplication()
{
	return new Sandbox();
}