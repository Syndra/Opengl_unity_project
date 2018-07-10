#include "Renderer.h"
#include "Shader.h"
#include "Transform.h"
#include "Vertex_data.h"
#include "Camera.h"
#include "CameraTransform.h"
#include "Mesh.h"

Renderer::Renderer(Transform *transform)
{
	//default setting.
	this->shader = Shader::BasicLightShader;
	this->transform = transform;
}


void Renderer::render(Camera * camera)
{
	if (this->onRenderTarget) {
		//shader should be derived from higher class.
		glUseProgram(shader);
		glBindVertexArray(this->VAO);

		glm::mat4 mvp = camera->get_projection_matrix() * camera->get_view_matrix() * compute_model_matrix();
		glm::mat4 model = compute_model_matrix();

		GLuint MatrixID = glGetUniformLocation(shader, "MVP");
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

		GLuint MatrixID_M = glGetUniformLocation(shader, "Model");
		glUniformMatrix4fv(MatrixID_M, 1, GL_FALSE, &model[0][0]);

		GLuint cameraPos = glGetUniformLocation(shader, "viewpos");
		glm::vec3 camerapos = camera->transform->position;
		glUniform3fv(cameraPos, 1, &camerapos[0]);

		//texture
		GLuint texture = glGetUniformLocation(shader, "texture2D");
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mesh->Texture);
		glUniform1i(texture, 0);

		//color
		GLuint Color = glGetUniformLocation(shader, "Color");
		glUniform3fv(Color, 1, &mesh->color[0]);

		//glDrawArrays(GL_TRIANGLES, 0, vertex_num / 3);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);

		glDrawElements(
			GL_TRIANGLES,      // mode
			mesh->indices.size(),    // count
			GL_UNSIGNED_SHORT,   // type
			(void*)0           // element array buffer offset
		);
	}
}

void Renderer::set_VBO()
{
	//Init VAO
	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);
	
	//Set buffer by model data.
	glGenBuffers(1, &this->VBO_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_vertices);
	glBufferData(GL_ARRAY_BUFFER, mesh->vertices.size() * sizeof(glm::vec3), &mesh->vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &this->VBO_uvs);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_uvs);
	glBufferData(GL_ARRAY_BUFFER, mesh->uvs.size() * sizeof(glm::vec2), &mesh->uvs[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &this->VBO_normals);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_normals);
	glBufferData(GL_ARRAY_BUFFER, mesh->normals.size() * sizeof(glm::vec3), &mesh->normals[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &this->EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->indices.size() * sizeof(unsigned int), &mesh->indices[0], GL_STATIC_DRAW);
	
	glBindVertexArray(0);
}

void Renderer::set_mesh(Mesh * mesh)
{
	this->mesh = mesh;

	set_VBO();

	onRenderTarget = true;
}

void Renderer::set_shader(char* V_shader, char* F_shader)
{
	this->shader = Shader::LoadShaders(V_shader, F_shader);
}

void Renderer::set_shader(GLuint shader)
{
	this->shader = shader;
}

glm::mat4 Renderer::compute_model_matrix()
{
	return glm::translate(glm::mat4(1.0f), this->transform->position) * glm::scale(glm::mat4(1.0), glm::vec3(this->transform->scale));
}
