#pragma once

#include "Quartz/Core.h"
#include "Quartz/Events/Event.h"

namespace Quartz
{
	// abstract class from which other engine layer classes will derive from
	class  Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRenderer() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;

	};
}



