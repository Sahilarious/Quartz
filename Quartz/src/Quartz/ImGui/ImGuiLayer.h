#pragma once

#include "Quartz/Layer.h"


namespace Quartz
{
	class QUARTZ_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		float m_Time = 0.0f;

		//static ImGuiLayer* s_Instance;
	};

}


