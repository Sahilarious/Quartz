#include "qzpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>


namespace Quartz
{
	OpenGLContext::OpenGLContext(GLFWwindow * windowHandle) 
		: m_WindowHandle(windowHandle)
	{
		QZ_CORE_ASSERT(windowHandle, "Window handle is null!");

	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		QZ_CORE_ASSERT(status, "Failed to initialize Glad");

		QZ_CORE_INFO("OpenGL Info: ");
		QZ_CORE_INFO("   Vendor: {0}", glGetString(GL_VENDOR));
		QZ_CORE_INFO("   Renderer: {0}", glGetString(GL_RENDERER));
		QZ_CORE_INFO("   Version: {0}", glGetString(GL_VERSION));


	}

	void OpenGLContext::SwapBuffers() 
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}