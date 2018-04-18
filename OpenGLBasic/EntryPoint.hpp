#pragma once
#include <iostream>
#include <GL\glew.h>

/*including glfw (Always include glew before glfw,
These are only for windows so please keep your openg code in different place so that u can use then for other platform too).
*/

#include <GLFW\glfw3.h>
#include <Constants.hpp>
#include <GLStart.hpp>
using namespace std;

class EntryPoint
{
private:
public:
	EntryPoint();
	~EntryPoint();
	void key_callback(GLFWwindow * window, int key, int scancode, int action, int mode);
};

