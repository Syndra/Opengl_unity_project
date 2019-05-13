#include "Coordinator.h"
#include "Scene.h"
#include "Shader.h"
#include <iostream>


Coordinator::Coordinator()
{
	
}


Coordinator::~Coordinator()
{
}

void Coordinator::draw_coordinate()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex_data), Vertex_data, GL_STATIC_DRAW);

	glUseProgram(Shader::Coordinate);

	GLuint MatrixID = glGetUniformLocation(Shader::Coordinate, "MVP");
	glm::mat4 mvp = Scene::camera_in_scene->get_projection_matrix() * Scene::camera_in_scene->get_view_matrix();
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid *)0);

	glDrawArrays(GL_LINES, 0, 6);
}
