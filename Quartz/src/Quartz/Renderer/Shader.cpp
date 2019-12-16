#include "qzpch.h"
#include "Shader.h"

#include "Quartz/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Quartz
{
	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			QZ_CORE_ASSERT(false, "RendererAPI::None is not supported.");
		case RendererAPI::OpenGL:
			return new OpenGLShader(vertexSrc, fragmentSrc);
		}
		QZ_CORE_ASSERT(false, "Unknown RendererAPI.");

		return nullptr;
	}
}

