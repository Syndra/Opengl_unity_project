#pragma once
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include "BaseObject.h"

class Camera;

class Tetris_block : public BaseObject
{
public:

	//Would be in psysic.c
	GLfloat gravity = 1.f;

	GLfloat speed;

	glm::vec3 position;

	//mesh properties.
	GLfloat* position_data;
	GLfloat* color_data;
	GLint vertex_num;

	//render properties.
	GLuint VAO;
	GLuint VBO_position;
	GLuint VBO_color;

	//Temporary properties.
	GLuint programID; // Should be in windows or some higher class. For test.

	Tetris_block();
	~Tetris_block();

	void render(Camera *camera);
	void set_mesh();
	void set_mesh(GLuint type);
	void update();
	glm::mat4 compute_model_matrix();
};

