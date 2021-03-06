#pragma once

#include "Quartz/Renderer/Buffer.h"

namespace Quartz
{
	//////////////////////////////// Vertex Buffer ////////////////////////////////

	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		virtual ~OpenGLVertexBuffer() override;
	
		virtual void Bind() const override;
		virtual void Unbind() const override;

	private:
		uint32_t m_RendererID;

	};

	//////////////////////////////// Index Buffer ////////////////////////////////

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		virtual ~OpenGLIndexBuffer() override;

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual uint32_t GetCount() const { return m_Count; };

	private:
		uint32_t m_RendererID;
		uint32_t m_Count;
	};

}