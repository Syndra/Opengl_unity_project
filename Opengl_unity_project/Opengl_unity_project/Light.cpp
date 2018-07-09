#include "Light.h"
#include "Shader.h"
#include "Transform.h"
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>


Light::Light(Transform *transform)
{
	this->transform = transform;
}


Light::~Light()
{
}

void Light::refresh()
{
	glUseProgram(Shader::BasicLightShader);

	GLuint as = glGetUniformLocation(Shader::BasicLightShader, "ambientStrength"); //float
	GLuint ss = glGetUniformLocation(Shader::BasicLightShader, "specularStrength"); //float
	GLuint lc = glGetUniformLocation(Shader::BasicLightShader, "lightColor"); //vec3
	GLuint lp = glGetUniformLocation(Shader::BasicLightShader, "lightPos"); //vec3
	
	glUniform1f(as, this->ambientStrengh);
	glUniform1f(ss, this->specularStrenth);
	glUniform3fv(lc, 1, &this->lightColor[0]);
	glUniform3fv(lp, 1, &this->transform->position[0]);
}
