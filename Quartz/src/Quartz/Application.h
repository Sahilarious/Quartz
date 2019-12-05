#pragma once

#include "Core.h"
#include "Window.h"

#include "Quartz/LayerStack.h"
#include "Events/Event.h"
#include "Quartz/Events/ApplicationEvent.h"

#include "Quartz/ImGui/ImGuiLayer.h"


namespace Quartz
{ 
	class  Application
	{
	public:
		Application();
		virtual ~Application();

	void Run();

	void OnEvent(Event& e);

	void PushLayer(Layer* layer);
	void PushOverlay(Layer* layer);

	static inline Application& Get() { return *s_Instance; }
	inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;

		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	// to be defined in client
	Application * CreateApplication();
}
