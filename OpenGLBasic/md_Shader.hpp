#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>
using namespace std;

class md_Shader
{
public:
	//Shader id for program
	GLuint md_Program;
	//Custructors & destructors
	md_Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	~md_Shader();
	//using
	void md_Use();
	void beforeStratRendering();
	void render();
	void afterEndRendering();
private:

};

