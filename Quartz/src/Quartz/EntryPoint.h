#pragma once

#ifdef QZ_PLATFORM_WINDOWS

extern Quartz::Application * Quartz::CreateApplication();

int main(int argc, char** argv)
{

	Quartz::Log::Init();
	QZ_CORE_WARN("Initialized Log!");
	QZ_CORE_INFO("Hi!! Hi!!");
	int a = 9;
	QZ_CORE_INFO("Var={0}", a);

	auto app = Quartz::CreateApplication();
	app->Run();
	delete app;

	return 0;
}


#endif