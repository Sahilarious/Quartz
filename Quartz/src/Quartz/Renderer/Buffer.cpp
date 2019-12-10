#include "qzpch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Quartz
{
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			QZ_CORE_ASSERT(false, "RendererAPI::None is not supported.");
		case RendererAPI::OpenGL:
			return new OpenGLVertexBuffer(vertices, size);
		}
		QZ_CORE_ASSERT(false, "Unknown RendererAPI.");

		return nullptr;
	}

	IndexBuffer * IndexBuffer::Create(uint32_t * indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			QZ_CORE_ASSERT(false, "RendererAPI::None is not supported.");
		case RendererAPI::OpenGL:
			return new OpenGLIndexBuffer(indices, size);
		}
		QZ_CORE_ASSERT(false, "Unknown RendererAPI.");

		return nullptr;
	}

}
