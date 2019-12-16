#include "qzpch.h"

#include "OpenGLShader.h"



namespace Quartz
{
	OpenGLShader::OpenGLShader(const std::string & vertexSrc, const std::string & fragmentSrc)
	{
		OpenGLShader::CreateAndCompileShader(m_VertexShaderID, vertexSrc, GL_VERTEX_SHADER);
		OpenGLShader::CreateAndCompileShader(m_FragmentShaderID, fragmentSrc, GL_FRAGMENT_SHADER);
		OpenGLShader::CreateProgram();
		OpenGLShader::LinkProgram();
	}

	void OpenGLShader::CreateAndCompileShader(uint32_t& shader, const std::string & shaderSrc, GLenum type)
	{
		//// Create an empty vertex shader handle
		shader = glCreateShader(type);

		// Send the vertex shader source code to GL
		// Note that std::string's .c_str is NULL character terminated.
		const GLchar *source = shaderSrc.c_str();
		glShaderSource(shader, 1, &source, 0);

		// Compile the vertex shader
		glCompileShader(shader);

		GLint isCompiled = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

			// We don't need the shader anymore.
			if (type == GL_FRAGMENT_SHADER)
			{
				glDeleteShader(m_VertexShaderID);
			}

			glDeleteShader(shader);

			QZ_CORE_ERROR("{0}", infoLog.data());
			QZ_CORE_ASSERT(false, "Vertex shader compilation error.");
			return;
		}
	}

	void OpenGLShader::CreateProgram()
	{
		// Vertex and fragment shaders are successfully compiled.
		// Now time to link them together into a program.
		// Get a program object.
		m_RendererID = glCreateProgram();

		// Attach our shaders to our program
		glAttachShader(m_RendererID, m_VertexShaderID);
		glAttachShader(m_RendererID, m_FragmentShaderID);
	}

	void OpenGLShader::LinkProgram()
	{
		// Link our program
		glLinkProgram(m_RendererID);

		// Note the different functions here: glGetProgram* instead of glGetShader*.
		GLint isLinked = 0;
		glGetProgramiv(m_RendererID, GL_LINK_STATUS, (int *)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(m_RendererID, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(m_RendererID, maxLength, &maxLength, &infoLog[0]);

			// We don't need the program anymore.
			glDeleteProgram(m_RendererID);
			// Don't leak shaders either.
			glDeleteShader(m_VertexShaderID);
			glDeleteShader(m_FragmentShaderID);

			// Use the infoLog as you see fit.

			// In this simple program, we'll just leave
			return;
		}

		// Always detach shaders after a successful link.
		glDetachShader(m_RendererID, m_VertexShaderID);
		glDetachShader(m_RendererID, m_FragmentShaderID);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RendererID);
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}

}