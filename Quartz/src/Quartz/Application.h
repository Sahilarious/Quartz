#pragma once

#include "Core.h"
#include "Window.h"

#include "Quartz/LayerStack.h"
#include "Events/Event.h"
#include "Quartz/Events/ApplicationEvent.h"


namespace Quartz
{ 
	class QUARTZ_API Application
	{
	public:
		Application();
		virtual ~Application();

	void Run();

	void OnEvent(Event& e);

	void PushLayer(Layer* layer);
	void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// to be defined in client
	Application * CreateApplication();
}
