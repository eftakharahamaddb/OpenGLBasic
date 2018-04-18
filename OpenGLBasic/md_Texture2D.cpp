#include "md_Texture2D.hpp"

md_Texture2D::md_Texture2D(const char* filename1)
{
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load and generate the texture

	unsigned char *textureData = SOIL_load_image(filename1, &width1, &height1, 0, SOIL_LOAD_RGB);
	/*unsigned char *textureData = stbi_load("brick.jpg", &width, &height, &channel, 0);*/

	if (textureData)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width1, height1, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData);
		glGenerateMipmap(GL_TEXTURE_2D);
		loaded1 = true;
		std::cout << "Success to load texture" << std::endl;
	}
	else
	{
		loaded1 = false;
		std::cout << "Failed to load texture" << std::endl;
	}
	SOIL_free_image_data(textureData);
}

md_Texture2D::md_Texture2D(const char * filename1, const char * filename2)
{
	//First image details
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load and generate the texture

	unsigned char *textureData = SOIL_load_image(filename1, &width1, &height1, 0, SOIL_LOAD_RGB);
	/*unsigned char *textureData = stbi_load("brick.jpg", &width, &height, &channel, 0);*/

	if (textureData)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width1, height1, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData);
		glGenerateMipmap(GL_TEXTURE_2D);
		loaded1 = true;
		std::cout << "Success to load texture1" << std::endl;
	}
	else
	{
		loaded1 = false;
		std::cout << "Failed to load texture1" << std::endl;
	}
	SOIL_free_image_data(textureData);
	glBindTexture(GL_TEXTURE_2D, 0);



	//Second image details
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load and generate the texture

	textureData = SOIL_load_image(filename2, &width2, &height2, 0, SOIL_LOAD_RGB);
	/*unsigned char *textureData = stbi_load("brick.jpg", &width, &height, &channel, 0);*/

	if (textureData)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width2, height2, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData);
		glGenerateMipmap(GL_TEXTURE_2D);
		loaded2 = true;
		std::cout << "Success to load texture2" << std::endl;
	}
	else
	{
		loaded1 = false;
		std::cout << "Failed to load texture2" << std::endl;
	}
	SOIL_free_image_data(textureData);
	glBindTexture(GL_TEXTURE_2D, 0);
}

md_Texture2D::~md_Texture2D()
{
}

GLint md_Texture2D::getWidth1()
{
	return width1;
}

GLint md_Texture2D::getWidth2()
{
	return width2;
}

GLint md_Texture2D::getHeight1()
{
	return height1;
}

GLint md_Texture2D::getHeight2()
{
	return height2;
}

GLboolean md_Texture2D::isLoaded1()
{
	return loaded1;
}

GLboolean md_Texture2D::isLoaded2()
{
	return loaded2;
}

void md_Texture2D::beforeStratRendering()
{

}
void md_Texture2D::render()
{

}

void md_Texture2D::afterEndRendering()
{

}



