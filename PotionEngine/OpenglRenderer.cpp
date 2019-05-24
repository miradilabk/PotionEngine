#include "OpenglRenderer.h"
#include "ResourceManager.h"
#include "GameWindow.h"
#include "Transform.h"

bool OpenglRenderer::hasInited = false;
GLuint OpenglRenderer::quadVAO = 0;
void OpenglRenderer::initRenderData()
{
	if (hasInited) return;
	// Configure VAO/VBO
	GLuint VBO;
	GLfloat vertices[] = {
		// Pos      // Tex
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f
	};

	glGenVertexArrays(1, &quadVAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(quadVAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	hasInited = true;
}

void OpenglRenderer::DrawSprite(
	Texture2D &texture, Shader &shader, 
	Transform2D *transform, glm::vec3 color,
	glm::vec2 origin)
{
	initRenderData();
	// Prepare transformations
	shader.Use();

	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(GameWindow::width),
		static_cast<GLfloat>(GameWindow::height), 0.0f, -1.0f, 1.0f);
	shader.SetInteger("image", 0);
	shader.SetMatrix4("projection", projection);
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(transform->position, 0.0f));
	model = glm::rotate(model, glm::radians(transform->rotation), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(-origin.x, -origin.y, 0.0f));

	model = glm::scale(model, glm::vec3(transform->size, 1.0f));

	shader.SetMatrix4("model", model);
	shader.SetVector3f("spriteColor", color);

	glActiveTexture(GL_TEXTURE0);
	texture.Bind();

	glBindVertexArray(quadVAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}