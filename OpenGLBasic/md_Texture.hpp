#pragma once
#include <SOIL.h>
#include "md_Shader.hpp"
#include <iostream>
class md_Texture
{
public:
	//Shader to use draw texture
	md_Shader* shader;
	GLint width, height, channel;
	GLint width1, height1, channel1;
	GLuint texture;
	GLuint texture1;
	GLuint  VBO, VAO, EBO;
	md_Texture();
	~md_Texture();
	void render();
	void afterRender();
};

