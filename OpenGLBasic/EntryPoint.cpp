#include "EntryPoint.hpp"
//including glew


EntryPoint::EntryPoint()
{

}

EntryPoint::~EntryPoint()
{

}

void EntryPoint:: key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	cout << "key_callback:key=" << key << ",scancode=" << scancode << ",action=" << action << ",mode=" << mode;
	// When a user presses the escape key, we set the WindowShouldClose property to true, closing the application

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	cout << "key_callback:key=" << key << ",scancode=" << scancode << ",action=" << action << ",mode=" << mode;
	// When a user presses the escape key, we set the WindowShouldClose property to true, closing the application

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}



int main()
{


	//Initializing GLFW for windows
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//Creating window of owr own desing
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "OpenGLBasic", nullptr, nullptr);
	if (window == nullptr)
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

	GLStart glstart;
	EntryPoint entryPoint;
	glfwSetKeyCallback(window, entryPoint.key_callback);

	glstart.beforeRendered();

	while (!glfwWindowShouldClose(window))
	{

		glfwPollEvents();
		glEnable(GL_DEPTH_TEST);
		//clearing screen with color bufferbit
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Put your rendering here
		GLfloat deltaTime = (GLfloat)glfwGetTime();
		glstart.render(deltaTime);

		//Swaping buffer
		glfwSwapBuffers(window);
	}

	glstart.afterRendered();

	glfwTerminate();
	return 0;
}

