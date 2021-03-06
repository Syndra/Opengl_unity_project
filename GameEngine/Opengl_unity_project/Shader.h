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

	static GLuint NoLightShader;
	static GLuint BasicLightShader;
	static GLuint NoTextureShader;
	static GLuint DirShadowShader;
	static GLuint panel;
	static GLuint skybox;
	static GLuint AlphaTest;
	static GLuint GeoTest;
	static GLuint WaterShader;
	static GLuint Coordinate;

	static std::vector<GLuint> shaders;

	static GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);
	static GLuint LoadShaders(const char * vertex_file_path, const char * geometry_file_path, const char * fragment_file_path);
	
	static void init_all_shaders();

	Shader();
	~Shader();
};
