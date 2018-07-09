#include "Renderer.h"
#include "Shader.h"
#include "Transform.h"
#include "Vertex_data.h"
#include "Camera.h"
#include "CameraTransform.h"

Renderer::Renderer(Transform *transform)
{
	//default setting.
	//this->programID = Shader::LoadShaders("SimpleVertexShader.txt", "SimpleFragmentShader.txt");
	this->programID = Shader::LoadShaders("LightVertexShader.txt", "LightFragmentShader.txt");
	this->transform = transform;
	set_mesh();
}


void Renderer::render(Camera * camera)
{
	//programID should be derived from higher class.
	glUseProgram(programID);
	glBindVertexArray(this->VAO);

	glm::mat4 mvp = camera->get_projection_matrix() * camera->get_view_matrix() * compute_model_matrix();
	glm::mat4 model = compute_model_matrix();

	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

	GLuint MatrixID_M = glGetUniformLocation(programID, "Model");
	glUniformMatrix4fv(MatrixID_M, 1, GL_FALSE, &model[0][0]);

	GLuint cameraPos = glGetUniformLocation(programID, "viewpos");
	glm::vec3 camerapos =  camera->transform->position;
	glUniform3fv(cameraPos, 1, &camerapos[0]);

	glDrawArrays(GL_TRIANGLES, 0, vertex_num / 3);
}

void Renderer::set_mesh()
{
	//Should be set by parameter like String "triangle" or "sphere".
	//Set upon input mesh type value.

	//set model data(mesh).
	position_data = Vertex_data::cube_data;
	color_data = Vertex_data::cube_color_data;
	vertex_num = Vertex_data::cube_num;
	normal_data = Vertex_data::cube_normals;

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

	glGenBuffers(1, &this->VBO_normal);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_normal);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertex_num, normal_data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

void Renderer::set_shader(char* V_shader, char* F_shader)
{
	this->programID = Shader::LoadShaders(V_shader, F_shader);
}

glm::mat4 Renderer::compute_model_matrix()
{
	return glm::translate(glm::mat4(1.0f), this->transform->position) * glm::scale(glm::mat4(1.0), glm::vec3(this->transform->scale));
}
