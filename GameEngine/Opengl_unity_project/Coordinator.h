#pragma once

#include "gl/glew.h"

class Coordinator
{
public:

	

	float Vertex_data[18] =
	{
		1000.0f, 0.0f, 0.0f,
		0.0f, 1000.0f, 0.0f,
		0.0f, 1000.0f, 0.0f,
		0.0f, 0.0f, 1000.0f,
		0.0f, 0.0f, 1000.0f,
		1000.0f, 0.0f, 0.0f,
	};

	GLuint VAO, VBO;

	Coordinator();
	~Coordinator();
	void draw_coordinate();
};

