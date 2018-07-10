#include "Light.h"
#include "Shader.h"
#include "Transform.h"
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <string>
#include <iostream>

int Light::numofLight;

Light::Light(Transform *transform)
{
	this->transform = transform;
	this->lightID = Light::numofLight;
	this->Power = 1.f;
	Light::numofLight++;
}


Light::~Light()
{
	numofLight--;
}

void Light::refresh()
{
	for (int i = 0; i < Shader::shaders.size(); i++) {
		glUseProgram(Shader::shaders.at(i));

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

		GLuint as = glGetUniformLocation(Shader::shaders.at(i), asUniLoca.c_str()); //float
		GLuint ss = glGetUniformLocation(Shader::shaders.at(i), ssUniLoca.c_str()); //float
		GLuint pw = glGetUniformLocation(Shader::shaders.at(i), pwUniLoca.c_str()); //float
		GLuint lc = glGetUniformLocation(Shader::shaders.at(i), lcUniLoca.c_str()); //vec3
		GLuint lp = glGetUniformLocation(Shader::shaders.at(i), lpUniLoca.c_str()); //vec3

		GLuint nl = glGetUniformLocation(Shader::shaders.at(i), "numofLight");

		glUniform1f(as, this->ambientStrengh);
		glUniform1f(ss, this->specularStrenth);
		glUniform1f(pw, this->Power * Light::degree);
		glUniform3fv(lc, 1, &this->lightColor[0]);
		glUniform3fv(lp, 1, &this->transform->position[0]);

		glUniform1i(nl, Light::numofLight);
	}
}
