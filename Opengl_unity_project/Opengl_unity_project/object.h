#pragma once
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include "control.h"

class Camera;

class object
{
public:
	
	//basic properties.

	//transform properties.
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

	object();
	~object();

	//compute Model matrix.
	glm::mat4 compute_model_matrix();

	//render method.
	void render_object(Camera* camera);
	void set_mesh();
};

