#pragma once

#ifdef QZ_PLATFORM_WINDOWS

extern Quartz::Application * Quartz::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Quartz::CreateApplication();
	app->Run();
	delete app;

	return 0;
}


#endif