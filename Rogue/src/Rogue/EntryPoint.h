#pragma once

#ifdef RG_PLATFORM_WINDOWS

extern Rogue::Application* Rogue::CreateApplication(); 

int main(int argc,char** argv)
{
	auto app = Rogue::CreateApplication();
	app->Run();
	delete app;
}

#endif