#include "Renderer.h"
#include "Shader.h"
#include "Transform.h"
#include "Camera.h"
#include "CameraTransform.h"
#include "Mesh.h"
#include "Model.h"

Renderer::Renderer(Transform *transform)
{
	//default setting.
	//this->shader = Shader::BasicLightShader;
	this->transform = transform;
}


void Renderer::render(Camera * camera)
{
	if (this->onRenderTarget) {

		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		glUseProgram(shader);
		glCullFace(GL_BACK);
		glm::mat4 mvp = camera->get_projection_matrix() * camera->get_view_matrix() * compute_model_matrix();
		glm::mat4 model = compute_model_matrix();

		GLuint MatrixID = glGetUniformLocation(shader, "MVP");
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

		GLuint MatrixID_M = glGetUniformLocation(shader, "Model");
		glUniformMatrix4fv(MatrixID_M, 1, GL_FALSE, &model[0][0]);

		GLuint cameraPos = glGetUniformLocation(shader, "viewpos");
		glm::vec3 camerapos = camera->transform->position;
		glUniform3fv(cameraPos, 1, &camerapos[0]);

		for (int loop = 0; loop < this->model->meshes.size(); loop++) 
		{
			glBindVertexArray(this->model->meshes.at(loop).VAO);

			//color
			GLuint Color = glGetUniformLocation(shader, "Color");
			glUniform3fv(Color, 1, &this->model->meshes.at(loop).color[0]);

			//texture
			GLuint texture = glGetUniformLocation(shader, "texture2D");
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, this->model->meshes.at(loop).TextureID);
			glUniform1i(texture, 1);

			//glDrawArrays(GL_TRIANGLES, 0, vertex_num / 3);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->model->meshes.at(0).EBO);

			glDrawElements(
				GL_TRIANGLES,      // mode
				this->model->meshes.at(0).indices.size(),    // count
				GL_UNSIGNED_INT,   // type
				(void*)0           // element array buffer offset
			);
		}
	}
}

void Renderer::set_model(Model * model)
{
	this->model = model;

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
	return glm::translate(glm::mat4(1.0f), this->transform->position) * glm::scale(glm::mat4(1.0), glm::vec3(this->transform->scale)) * transform->get_rotationMat();
}
