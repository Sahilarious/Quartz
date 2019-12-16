#pragma once


#include "Quartz/Renderer/Shader.h"
#include "glad/glad.h"


namespace Quartz
{

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;

	private:

		void CreateAndCompileShader(uint32_t& shader, const std::string & vertexSrc, GLenum type);
		void CreateProgram();
		void LinkProgram();

	private:
		uint32_t m_VertexShaderID;
		uint32_t m_FragmentShaderID;

	};

}