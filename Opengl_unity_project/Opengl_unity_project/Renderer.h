#pragma once

#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>

class Model;
class Transform;
class Camera;

class Renderer
{
public:

	//True to render
	bool onRenderTarget = false;

	//Transform
	Transform * transform;

	//Shader
	GLuint shader;

	//Render Properties. (Mesh)
	Model *model;

	Renderer(Transform *transform);
	void render(Camera *camera);
	void set_model(Model *model);
	void set_shader(char* V_shader, char* F_shader);
	void set_shader(GLuint shader);

	glm::mat4 compute_model_matrix();
};

