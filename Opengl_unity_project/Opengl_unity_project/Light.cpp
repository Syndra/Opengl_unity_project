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

void Light::refresh()
{
	this->shadowMap->drawShadowMap();

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
		DepthMVPUniLoca = "lights["+ std::to_string(lightID)+"].DepthBiasVP";

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

		glUniform4fv(dbmvp,1, &this->shadowMap->depthBiasVP[0][0]);

		std::string sdwmapUniLoca;
		sdwmapUniLoca = "shadowMap[" + std::to_string(lightID) + "]";

		GLuint texture = glGetUniformLocation(Shader::shaders.at(i), sdwmapUniLoca.c_str());
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, this->shadowMap->depthTexture);
		glUniform1i(texture, 0);
	}


}
