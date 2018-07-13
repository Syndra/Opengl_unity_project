#include "Light.h"
#include "Shader.h"
#include "Transform.h"
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <string>
#include <iostream>
#include "Scene.h"
#include "Renderer.h"
#include "Model.h"
#include "Mesh.h"

int Light::numofLight;

Light::Light(Transform *transform)
{
	this->type = 1;
	this->transform = transform;
	this->lightID = Light::numofLight;
	this->Power = 1.f;
	Light::numofLight++;

	setShadowMap(type);
}


Light::~Light()
{
	numofLight--;
}

void Light::setShadowMap(int type) 
{
	this->shadowMap = new ShadowMap(this->transform->position, this->direction, type);
}

void Light::drawShadowMap()
{
	glBindFramebuffer(GL_FRAMEBUFFER, this->shadowMap->FrameBuffer);
	glViewport(0, 0, 1024, 1024); // Render on the whole framebuffer, complete from the lower left corner to the upper right

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK); // Cull back-facing triangles -> draw only front-facing triangles

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(Shader::DirShadowShader);
	//glm::vec3 lightInvDir = glm::vec3(0.5f, 2, 2);
	glm::vec3 lightInvDir = direction;

	// Compute the MVP matrix from the light's point of view
	glm::mat4 depthProjectionMatrix = glm::ortho<float>(-10, 10, -10, 10, -10, 20);
	glm::mat4 depthViewMatrix = glm::lookAt(lightInvDir, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	glm::mat4 depthModelMatrix = glm::mat4(1.0);
	glm::mat4 depthMVP = depthProjectionMatrix * depthViewMatrix * depthModelMatrix;

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	GLuint dr = glGetUniformLocation(Shader::DirShadowShader, "depthMVP");
	glUniformMatrix4fv(dr, 1, GL_FALSE, &depthMVP[0][0]);

	for (int i = 0; i < Scene::renderer.size(); i++) 
	{
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
	depthBiasMVP = biasMatrix * depthMVP;
}

void Light::refresh()
{
	drawShadowMap();

	for (int i = 0; i < Shader::shaders.size(); i++) {
		glUseProgram(Shader::shaders.at(i));

		std::string tpUniLoca;
		tpUniLoca = "lights[" + std::to_string(lightID) + "].type";
		std::string asUniLoca;
		asUniLoca = "lights[" + std::to_string(lightID) + "].ambientStrength";
		std::string ssUniLoca;
		ssUniLoca = "lights[" + std::to_string(lightID) + "].specularStrength";
		std::string lcUniLoca;
		lcUniLoca = "lights[" + std::to_string(lightID) + "].lightColor";
		std::string lpUniLoca;
		lpUniLoca = "lights[" + std::to_string(lightID) + "].lightPos";
		std::string pwUniLoca;
		pwUniLoca = "lights[" + std::to_string(lightID) + "].lightPower";
		std::string drUniLoca;
		drUniLoca = "lights[" + std::to_string(lightID) + "].lightDirection";

		std::string DepthMVPUniLoca;
		DepthMVPUniLoca = "lights["+ std::to_string(lightID)+"].DepthBiasMVP";

		GLuint tp = glGetUniformLocation(Shader::shaders.at(i), tpUniLoca.c_str()); //int
		GLuint as = glGetUniformLocation(Shader::shaders.at(i), asUniLoca.c_str()); //float
		GLuint ss = glGetUniformLocation(Shader::shaders.at(i), ssUniLoca.c_str()); //float
		GLuint pw = glGetUniformLocation(Shader::shaders.at(i), pwUniLoca.c_str()); //float
		GLuint lc = glGetUniformLocation(Shader::shaders.at(i), lcUniLoca.c_str()); //vec3
		GLuint lp = glGetUniformLocation(Shader::shaders.at(i), lpUniLoca.c_str()); //vec3
		GLuint dr = glGetUniformLocation(Shader::shaders.at(i), drUniLoca.c_str()); //vec3

		GLuint nl = glGetUniformLocation(Shader::shaders.at(i), "numofLight");

		GLuint dbmvp = glGetUniformLocation(Shader::shaders.at(i), DepthMVPUniLoca.c_str()); //mat4

		glUniform1i(tp, this->type);
		glUniform1f(as, this->ambientStrengh);
		glUniform1f(ss, this->specularStrenth);
		glUniform1f(pw, this->Power * Light::degree);
		glUniform3fv(lc, 1, &this->lightColor[0]);
		glUniform3fv(lp, 1, &this->transform->position[0]);
		glUniform3fv(dr, 1, &this->direction[0]);

		glUniform1i(nl, Light::numofLight);

		glUniform4fv(dbmvp,1, &this->depthBiasMVP[0][0]);

		std::string sdwmapUniLoca;
		sdwmapUniLoca = "shadowMap[" + std::to_string(lightID) + "]";

		GLuint texture = glGetUniformLocation(Shader::shaders.at(i), sdwmapUniLoca.c_str());
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, this->shadowMap->depthTexture);
		glUniform1i(texture, 0);
	}


}
