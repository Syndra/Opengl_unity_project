#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <vector>
class Shader
{
public:

	static GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);
	Shader();
	~Shader();
};

