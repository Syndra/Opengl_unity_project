#pragma once
#include <gl\glew.h>
#include <GLFW\glfw3.h>

class Vertex_data
{
public:
	Vertex_data();
	~Vertex_data();

	static const GLint vertex_num = 9;
	static const GLint cube_num = 108;
	static const GLint floor_num = 18;

	static GLfloat cube_color_data[108];
	static GLfloat textureCoordinate[6];
	static GLfloat tri_data[9];
	static GLfloat cube_data[108];
	static GLfloat cube_normals[108];
	static GLfloat color[9];

	static GLfloat floor[18];
	static GLfloat floor_color[18];

	static GLfloat panel[18];
	static GLfloat panel_uv[12];
};

