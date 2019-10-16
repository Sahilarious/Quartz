#include <Quartz.h>

class ExampleLayer : public Quartz::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		if (Quartz::Input::IsKeyPressed(QZ_KEY_TAB))
		{
			QZ_INFO("Tab pressed!!!!!!!!!!!!! (poll)");
		}
	}

	void OnEvent(Quartz::Event& event) override
	{
		if (event.GetEventType() == Quartz::EventType::KeyPressed)
		{
			Quartz::KeyPressedEvent& e = (Quartz::KeyPressedEvent&)event;
			if (Quartz::Input::IsKeyPressed(QZ_KEY_TAB))
			{
				QZ_INFO("Tab pressed!!!!!!!!!!!!! (event)");
			}
			QZ_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Quartz::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Quartz::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Quartz::Application* Quartz::CreateApplication()
{

	

	return new Sandbox();
}