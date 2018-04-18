#include "SmileyFace.hpp"
// GLFW

SmileyFace::SmileyFace()
{
	shader = new md_Shader("smiley.vs", "smiley.frag");
	texture = new md_Texture2D("images/container.jpg", "images/smiley.png");

	//GLfloat vertices[] = {
	//	// Texture Coords
	//	0.5f,  0.5f, 0.0f,    1.0f, 0.0f, // Top Right
	//	0.5f, -0.5f, 0.0f,    1.0f, 1.0f, // Bottom Right
	//	-0.5f, -0.5f, 0.0f,   0.0f, 1.0f, // Bottom Left
	//	-0.5f,  0.5f, 0.0f,   0.0f, 0.0f  // Top Left 
	//};

	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	GLuint indices[] =
	{
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};



	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

}


SmileyFace::~SmileyFace()
{
	delete shader;
	delete texture;

}

void SmileyFace::beforeStratRendering()
{
	shader->beforeStratRendering();
	texture->beforeStratRendering();
}

void SmileyFace::render(GLfloat deltaTime)
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture->texture1);
	glUniform1i(glGetUniformLocation(shader->md_Program, "ourTexture1"), 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture->texture2);
	glUniform1i(glGetUniformLocation(shader->md_Program, "ourTexture2"), 1);

	texture->render();
	shader->render();


	GLint modelLoc = glGetUniformLocation(shader->md_Program, "model");
	GLint viewLoc = glGetUniformLocation(shader->md_Program, "view");
	GLint projLoc = glGetUniformLocation(shader->md_Program, "projection");

	// Pass them to the shaders

	GLfloat radious = 10.0f;
	GLfloat cameraX = sin(deltaTime)* radious;
	GLfloat cameraZ = cos(deltaTime)* radious;
	glm::vec3 cameraPosition = glm::vec3(cameraX, 0.0f, cameraZ);
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 view;
	glm::mat4 projection;
	//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -2.5f));
	view = glm::lookAt(cameraPosition, cameraTarget, cameraUp);
	projection = glm::perspective(45.0f, (GLfloat)windowWidth / (GLfloat)windowHeight, 0.1f, 100.0f);

	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	glBindVertexArray(VAO);
	for (GLuint i = 0; i < 10; i++)
	{
		glm::mat4 model;
		model = glm::translate(model, cubePosiion[i]);
		GLfloat angle = 20.0f*i;
		model = glm::rotate(model, angle, glm::vec3(0.5f, 1.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
	glBindVertexArray(0);
}

void SmileyFace::afterEndRendering()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	shader->afterEndRendering();
	texture->afterEndRendering();
}
