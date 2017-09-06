#include "Application.h"
#include "gl_core_4_4.h"
#include <GLFW\glfw3.h>
#include <>


Application::Application()
{
}


Application::~Application()
{
}

void Application::run(const char* title, unsigned int width, unsigned int height, bool fullscreen)
{
	if (glfwInit() == GL_FALSE)
		return;
	GLFWmonitor* monitor = (fullscreen) ? glfwGetPrimaryMonitor() : nullptr;
	m_window = glfwCreateWindow(width, height, title, monitor, nullptr);
	glfwMakeContextCurrent(m_window);
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return;
	}
	glClearColor(.75, .75, .75, 1);
	glEnable(GL_DEPTH_TEST);
	
}