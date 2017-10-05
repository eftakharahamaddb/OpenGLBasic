//including glew
//#define GLEW_STATIC
#include <iostream>
#include <GL\glew.h>

/*including glfw (Always include glew before glfw,
These are only for windows so please keep your openg code in different place so that u can use then for other platform too).
*/

#include <GLFW\glfw3.h>

int main()
{

	GLint windowWidth  = 480;
	GLint windowHeight = 720;

	//Initializing GLFW for windows
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);


	//Creating window of owr own desing
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "OpenGLBasic", nullptr, nullptr);
	if(window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	//initializing GLEW so before any OpenGL Functions

	glewExperimental = GL_TRUE; //some time not found, it is for udated running vesions.
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}
	glViewport(0, 0, windowWidth, windowHeight);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;

}
