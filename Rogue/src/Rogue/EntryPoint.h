#pragma once

#ifdef RG_PLATFORM_WINDOWS

extern Rogue::Application* Rogue::CreateApplication(); 

int main(int argc,char** argv)
{

	Rogue::Log::Init();
	RG_CORE_WARN("Initialized Log!");
	int a = 4;
	RG_INFO("Initialized Log! {0}",a);
	auto app = Rogue::CreateApplication();
	app->Run();
	delete app;
}

#endif 