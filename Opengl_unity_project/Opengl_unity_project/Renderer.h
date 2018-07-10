#pragma once

#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>

class Mesh;
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

	//VAO, VBO
	GLuint VAO;
	GLuint EBO;
	GLuint VBO_vertices;
	GLuint VBO_uvs;
	GLuint VBO_normals;

	//Render Properties. (Mesh)
	Mesh *mesh;

	GLfloat* position_data;
	GLfloat* color_data;
	GLfloat* normal_data;
	GLint vertex_num;

	Renderer(Transform *transform);
	void render(Camera *camera);
	void set_VBO();
	void set_mesh(Mesh *mesh);
	void set_shader(char* V_shader, char* F_shader);
	void set_shader(GLuint shader);

	glm::mat4 compute_model_matrix();
};

