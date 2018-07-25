#include "ShadowMap.h"
#include "Shader.h"
#include "Scene.h"
#include "Renderer.h"
#include "Model.h"
#include "Mesh.h"
#include "Window.h"
#include "Transform.h"
#include "LightTransform.h"
#include "Light.h"

ShadowMap::ShadowMap(Transform * transform, LightProperties * properties)
{
	shader = Shader::DirShadowShader;

	this->transform = transform;

	this->properties = properties;

	if (properties->type == 0)
	{
		this->setupDirectedShadowMap();

	}
	if (properties->type == 1)
	{
		this->setupSpotShadowMap();
	}
}


ShadowMap::~ShadowMap()
{
}

bool ShadowMap::setupDirectedShadowMap()
{
	glGenFramebuffers(1, &FrameBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, FrameBuffer);

	// Depth texture. Slower than a depth buffer, but you can sample it later in your shader
	glGenTextures(1, &depthTexture);
	glBindTexture(GL_TEXTURE_2D, depthTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, 1024, 1024, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,depthTexture,0);

	glDrawBuffer(GL_NONE); // No color buffer is drawn to.
	//glReadBuffer(GL_NONE);

	//					   // Always check that our framebuffer is ok
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		return false;

	
}

bool ShadowMap::setupSpotShadowMap()
{
	glGenFramebuffers(1, &FrameBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, FrameBuffer);

	// Depth texture. Slower than a depth buffer, but you can sample it later in your shader
	glGenTextures(1, &depthTexture);
	glBindTexture(GL_TEXTURE_2D, depthTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, 1024, 1024, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthTexture, 0);

	glDrawBuffer(GL_NONE); // No color buffer is drawn to.
						   //glReadBuffer(GL_NONE);

						   //					   // Always check that our framebuffer is ok
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		return false;

	
}

void ShadowMap::drawShadowMap()
{
	if (properties->type == 0)
	{
		glm::vec3 lightInvDir = transform->get_dir();

		glm::mat4 depthProjectionMatrix = glm::ortho<float>(-10, 10, -10, 10, -10, 20);
		glm::mat4 depthViewMatrix = glm::lookAt(lightInvDir, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
		this->depthVP = depthProjectionMatrix * depthViewMatrix;

	}
	if (properties->type == 1)
	{
		glm::mat4 depthProjectionMatrix = glm::perspective(glm::radians(90.f), 1.0f, 0.1f, 100.f);
		glm::mat4 depthViewMatrix = glm::lookAt(this->transform->position + glm::vec3(0.000001), this->transform->get_Lookat(), glm::vec3(0, 1, 0));
		this->depthVP = depthProjectionMatrix * depthViewMatrix;

	}
	glBindFramebuffer(GL_FRAMEBUFFER, this->FrameBuffer);
	//glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glUseProgram(shader);
	glViewport(0, 0, 1024, 1024); // Render on the whole framebuffer, complete from the lower left corner to the upper right

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK); // Cull back-facing triangles -> draw only front-facing triangles

	glClear(GL_DEPTH_BUFFER_BIT);

	//draw
	for (int i = 0; i < Scene::renderer.size(); i++)
	{
		glm::mat4 depthModelMatrix = Scene::renderer.at(i)->compute_model_matrix();
		GLuint dmm = glGetUniformLocation(shader, "depthMVP");

		glm::mat4 depthMVP = this->depthVP * depthModelMatrix;

		glUniformMatrix4fv(dmm, 1, GL_FALSE, &depthMVP[0][0]);

		for (int j = 0; j < Scene::renderer.at(i)->model->meshes.size(); j++)
		{
			glBindVertexArray(Scene::renderer.at(i)->model->meshes.at(j).VAO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Scene::renderer.at(i)->model->meshes.at(j).EBO);
			glDrawElements(
				GL_TRIANGLES,      // mode
				Scene::renderer.at(i)->model->meshes.at(j).indices.size(),    // count
				GL_UNSIGNED_INT,   // type
				(void*)0           // element array buffer offset
			);
		}
	}

	glm::mat4 biasMatrix(
		0.5, 0.0, 0.0, 0.0,
		0.0, 0.5, 0.0, 0.0,
		0.0, 0.0, 0.5, 0.0,
		0.5, 0.5, 0.5, 1.0
	);
	this->depthBiasVP = glm::mat4(1);
	this->depthBiasVP = biasMatrix * this->depthVP ;
}