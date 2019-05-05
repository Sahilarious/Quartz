#pragma once

#include "Core.h"

namespace Quartz
{ 
	class QUARTZ_API Application
	{
	public:
		Application();
		virtual ~Application();



	void Run();

	};

	// to be defined in client
	Application * CreateApplication();
}
