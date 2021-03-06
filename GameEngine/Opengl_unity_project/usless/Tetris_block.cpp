#include "Tetris_block.h"
#include "Vertex_data.h"
#include "Camera.h"
#include "Shader.h"
#include "Window.h"
#include "Timer.h"


Tetris_block::Tetris_block()
{
	this->position = glm::vec3(0, 0, 0);
	this->programID = Shader::LoadShaders("SimpleVertexShader.txt", "SimpleFragmentShader.txt");
	this->speed = 5.f;
}


Tetris_block::~Tetris_block()
{
}

void Tetris_block::render(Camera *camera)
{
	//programID should be derived from higher class.
	glUseProgram(programID);
	glBindVertexArray(this->VAO);

	glm::mat4 mvp = camera->get_projection_matrix() * camera->get_view_matrix() * compute_model_matrix();

	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

	glDrawArrays(GL_TRIANGLES, 0, vertex_num / 3);
}

void Tetris_block::set_mesh()
{
	//Should be set by parameter like String "triangle" or "sphere".
	//Set upon input mesh type value.

	//set model data(mesh).
	position_data = Vertex_data::cube_data;
	color_data = Vertex_data::cube_color_data;
	vertex_num = Vertex_data::cube_num;

	//Init VAO
	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);

	//Set buffer by model data.
	glGenBuffers(1, &this->VBO_position);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_position);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertex_num, position_data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);


	glGenBuffers(1, &this->VBO_color);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_color);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertex_num, color_data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

void Tetris_block::set_mesh(GLuint type)
{
	//Should be set by parameter like String "triangle" or "sphere".
	//Set upon input mesh type value.

	//set model data(mesh).
	position_data = Vertex_data::cube_data;
	color_data = Vertex_data::cube_color_data;
	vertex_num = Vertex_data::cube_num;

	//Init VAO
	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);

	//Set buffer by model data.
	glGenBuffers(1, &this->VBO_position);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_position);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertex_num, position_data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);


	glGenBuffers(1, &this->VBO_color);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_color);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertex_num, color_data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

void Tetris_block::set_mesh_floor()
{
	//Should be set by parameter like String "triangle" or "sphere".
	//Set upon input mesh type value.

	//set model data(mesh).
	position_data = Vertex_data::floor;
	color_data = Vertex_data::floor_color;
	vertex_num = Vertex_data::floor_num;

	//Init VAO
	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);

	//Set buffer by model data.
	glGenBuffers(1, &this->VBO_position);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_position);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertex_num, position_data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);


	glGenBuffers(1, &this->VBO_color);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_color);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertex_num, color_data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

glm::mat4 Tetris_block::compute_model_matrix()
{
	return glm::translate(glm::mat4(1.0f), this->position) * glm::scale(glm::mat4(1.0), glm::vec3(0.5f));
}

void Tetris_block::update()
{
	//this->position.y -= Timer::deltatime * gravity;

	if (glfwGetKey(Window::window, GLFW_KEY_Z) == GLFW_PRESS) {
		this->position.y += Timer::deltatime * speed;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_X) == GLFW_PRESS) {
		this->position.y -= Timer::deltatime * speed;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_A) == GLFW_PRESS) {
		this->position.x += Timer::deltatime * speed;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_S) == GLFW_PRESS) {
		this->position.x -= Timer::deltatime * speed;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_Q) == GLFW_PRESS) {
		this->position.z += Timer::deltatime * speed;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_W) == GLFW_PRESS) {
		this->position.z -= Timer::deltatime * speed;
	}
}

