#pragma once
#include <SOIL.h>
#include <iostream>
#include <GL/glew.h>
#include <Methods.hpp>


class md_Texture2D :public Methods
{
private:
	GLint width1, height1, channel1, width2, height2, channel2;
	GLboolean loaded1, loaded2;
public:
	md_Texture2D(const char* filename1);
	md_Texture2D(const char* filename1, const char *filename2);
	~md_Texture2D();
	GLuint texture1;
	GLuint texture2;
	GLint getWidth1();
	GLint getWidth2();
	GLint getHeight1();
	GLint getHeight2();
	GLboolean isLoaded1();
	GLboolean isLoaded2();
	void beforeStratRendering();
	void render();
	void afterEndRendering();
};

