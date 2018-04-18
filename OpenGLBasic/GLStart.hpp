#pragma once
#include <iostream>
#include <GL\glew.h>
#include <md_Shader.hpp>
#include <md_Texture.hpp>
#include <SmileyFace.hpp>

using namespace std;

class GLStart:Methods
{

public:
	GLStart();
	~GLStart();
	void createShaders();
	void createShadersFromFile();
	void createShadersAssign3();
	void createTriangleData();
	void createRectangleData();
	void createAssignment1();
	void createAssignment2();
	void createAssignment3();
	void createTriangleUsingExterShader();
	void beforeRendered();
	void renderTriangle();
	void renderRectangle();
	void renderAssignment1();
	void renderAssignment2();
	void renderAssignment3();
	void renderFromFileShaer();
	void render(GLfloat deltaTime);
	void afterRendered();
	void key_callback(int key, int scancode, int action, int mode);
	
private:

	md_Shader * shader;
	md_Texture * texture;
	SmileyFace * smileyFace;
	//Passign ccolor values from one shader to another shader using in and out type variable
	//Vertex Shader
	const GLchar* vertexShaderSourcePass = "#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		"out vec4 mycolor;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
		"mycolor = vec4(position,1.0f)\n;"
		"}\0";


	//Fragment Shader
	const GLchar* fragmentShaderSource1Pass = "#version 330 core\n"
		"in vec4 mycolor;\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = mycolor;\n"
		"}\n\0";


	//Fragment Shader
	const GLchar* fragmentShaderSource2Pass = "#version 330 core\n"
		"in vec4 mycolor;\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = mycolor;\n"
		"}\n\0";


	//Vertex Shader
	const GLchar* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
		"}\0";
	GLuint vertexShader;
	GLint  success;
	GLchar infoLog[512];

	//Fragment Shader
	const GLchar* fragmentShaderSource1 = "#version 330 core\n"
		"out vec4 color;\n"
		
		"void main()\n"
		"{\n"
		"color = vec4(0.5f, 0.1f,0.1f,1.0f);\n"
		"}\n\0";

	//Fragment Shader
	const GLchar* fragmentShaderSource1UniformColor = "#version 330 core\n"
		"out vec4 color;\n"
		"uniform vec4 unifColor;\n"
		"void main()\n"
		"{\n"
		"color = unifColor;\n"
		"}\n\0";

	GLuint fragmentShader1;
	//Shader program
	GLuint shaderProgram1;

	//Fragment Shader
	const GLchar* fragmentShaderSource2 = "#version 330 core\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = vec4(0.5f, 0.5f,0.5f,1.0f);\n"
		"}\n\0";	

	GLuint fragmentShader2;
	//Shader Program
	GLuint shaderProgram2;

	//Vertices
	GLfloat vertices[9] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f };
	//Vertex Buffer Object
	GLuint VBO;

	//Vertex Array Object
	GLuint VAO;


	//for two rctenagle
	GLfloat vierticesRect[12] = 
	{ 
		0.5f, 0.5f, 0.0f, // Top Right
		0.5f, -0.5f, 0.0f, // Bottom Right
		-0.5f, -0.5f, 0.0f, // Bottom Left
		-0.5f, 0.5f, 0.0f // Top Left
	};

	GLuint indicesRect[6] = 
	{ 
		0, 1, 3, // First Triangle
		1, 2, 3 // Second Triangle
	};

	GLuint EBO;


	//Assignment 1
	
	GLfloat verticesAssign1[18] = {
		-0.9f, -0.5f, 0.0f,  // Left 
		-0.0f, -0.5f, 0.0f,  // Right
		-0.45f, 0.5f, 0.0f,  // Top 
		// Second triangle
		 0.0f, -0.5f, 0.0f,  // Left
		 0.9f, -0.5f, 0.0f,  // Right
		 0.45f, 0.5f, 0.0f   // Top 
	};


	GLfloat assign2Tri1[9]
	{
		-0.9f, -0.5f, 0.0f,  // Left 
		-0.0f, -0.5f, 0.0f,  // Right
		-0.45f, 0.5f, 0.0f,  // Top 
	};

	GLfloat assign2Tri2[9]
	{
		0.0f, -0.5f, 0.0f,  // Left
		0.9f, -0.5f, 0.0f,  // Right
		0.45f, 0.5f, 0.0f   // Top 
	};

	GLuint VBOs[2], VAOs[2];

	//2Attribute
	GLfloat verticesBoth[18] = {
		// Positions         // Colors
		0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  // Bottom Left
		0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f   // Top 
	};
};

