#include "object.h"
#include "Vertex_data.h"
#include "Camera.h"
#include "Shader.h"

object::object()
{
	//set default transform properties.
	this->position = glm::vec3(0,0,0);

	//test. Should be in windows.
	this->programID = Shader::LoadShaders("SimpleVertexShader.txt", "SimpleFragmentShader.txt");
}

object::~object()
{
}

glm::mat4 object::compute_model_matrix()
{
	return glm::translate(glm::mat4(1.0f), this->position);
}

void object::render_object(Camera* camera)
{
	//programID should be derived from higher class.
	glUseProgram(programID);
	glBindVertexArray(this->VAO);

	glm::mat4 mvp = camera->get_projection_matrix() * camera->get_view_matrix() * compute_model_matrix();
	//glm::mat4 mvp = glm::mat4(1.0f);
	
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);	

	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void object::set_mesh()
{
	//Should be set by parameter like String "triangle" or "sphere".
	//Set upon input mesh type value.

	//set model data(mesh).
	this->position_data = Vertex_data::tri_data;
	this->color_data = Vertex_data::color;
	this->vertex_num = Vertex_data::vertex_num;

	//Init VAO
	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);

	//Set buffer by model data.
	glGenBuffers(1, &this->VBO_position);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_position);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * this->vertex_num, this->position_data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );
	

	glGenBuffers(1, &this->VBO_color);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_color);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * this->vertex_num, this->color_data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );
}
