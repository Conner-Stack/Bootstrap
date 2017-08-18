#include "gl_core_4_4.h"
#include <GLFW\glfw3.h>
#include <cstdio>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <cassert>
#include <iostream>
int main()
{

	
	glm::vec3 v = glm::vec3(1, 1, 1);


	//checks for glfw initialization
	//if false, breaks out of program
	if (!glfwInit())
		printf("no glfw");

	//creates a window  with the arguments being width, height, window name, fullscreen, and 
		//some kind of pointer named share, which i guess does.... hell i don't know
	GLFWwindow* window = glfwCreateWindow(800, 800, "test", NULL, NULL);

		//checks if the window variable is initialized
		//if false, breaks out of program
		if (!window)
		{
			//terminates glfw if no window is shown
			glfwTerminate();
			return-2;
		}
		//sends an error if the window evaluates to the nullptr value;
		assert(window != nullptr);
		
		//sets the most recently initialized openGL context as the current one being used
		//ends upon context replacement or window destruction
		glfwMakeContextCurrent(window);

		if(ogl_LoadFunctions() == ogl_LOAD_FAILED)
		{
			glfwDestroyWindow(window);
			glfwTerminate();
			return -3;
		}

		auto major = ogl_GetMajorVersion;
		auto minor = ogl_GetMinorVersion;
		
		printf("GL: %i.%i\n", major, minor);
		glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
		//while loop that repeats while the window's close flag is not called
		while (true)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glfwPollEvents();
			if (glfwWindowShouldClose(window))
				break;
			if (glfwGetKey(window, GLFW_KEY_ESCAPE))
				glfwSetWindowShouldClose(window, true);
		}

		//destructs and deletes the current glfw window
		glfwDestroyWindow(window);
		//terminates glfw
		glfwTerminate();

	return 0;
}