#include <cstdio>
#include "gl_core_4_4.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
//held outside of the main function because it is a callback
//c-style error callback function where an int value of 0 returns an error to stderr
//and description is given the value of the glfwSetErrorCallback return
void error_callback(int error, const char* description)
{
	fprintf(stderr,"Error:%s\n" ,description);
}

int main()
{
	//sends error info to the callback function located above the main program
	glfwSetErrorCallback(error_callback);
	//checks for glfw initialization
	//if false, breaks out of program
	if (!glfwInit())
		return;
	
	//creates a window  with the arguments being width, height, window name, fullscreen, and 
	//some kind of pointer named share, which i guess does.... hell i don't know
	GLFWwindow* window = glfwCreateWindow(640, 480, "test", NULL, NULL);
	//checks if the window variable is initialized
	//if false, breaks out of program
	if (!window)
		return;
	
	//destructs and deletes the current glfw window
	glfwDestroyWindow(window);
	
	//sets the most recently initialized openGL context as the current one being used
	//ends upon context replacement or window destruction
	glfwMakeContextCurrent(window);





	glfwTerminate();
	return 0;
}