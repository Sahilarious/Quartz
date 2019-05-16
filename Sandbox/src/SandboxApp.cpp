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
		QZ_INFO("ExampleLayer::Update");
	}

	void OnEvent(Quartz::Event& event) override
	{
		QZ_TRACE("{0}", event);
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