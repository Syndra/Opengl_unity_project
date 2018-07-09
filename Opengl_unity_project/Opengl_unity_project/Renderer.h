#pragma once

#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>

class Transform;
class Camera;

class Renderer
{
public:

	//Transform
	Transform * transform;

	//Shader
	GLuint shader;

	//VAO, VBO
	GLuint VAO;
	GLuint VBO_position;
	GLuint VBO_color;
	GLuint VBO_normal;

	//Render Properties. (Mesh)
	GLfloat* position_data;
	GLfloat* color_data;
	GLfloat* normal_data;
	GLint vertex_num;

	Renderer(Transform *transform);
	void render(Camera *camera);
	void set_mesh();
	void set_shader(char* V_shader, char* F_shader);

	glm::mat4 compute_model_matrix();
};

