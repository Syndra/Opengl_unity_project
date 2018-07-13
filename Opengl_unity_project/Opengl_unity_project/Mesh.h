#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <gl\glew.h>
#include <glm\glm.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>

using namespace std;

struct Vertex
{
	// Position
	glm::vec3 Position;
	// Normal
	glm::vec3 Normal;
	// TexCoords
	glm::vec2 TexCoords;
};

struct Texture
{
	GLuint id;
	string type;
	aiString path;
};

class Mesh
{
public:

	/*  Mesh Data  */
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Texture> textures;

	const char * path;

	GLuint VAO, VBO, EBO;

	/*std::vector<unsigned short> indices;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;*/

	GLuint TextureID;

	glm::vec3 color = glm::vec3(1,1,1);

	Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);
	~Mesh();

	void Draw(GLuint programID);
	void setupMesh();
	void set_texture(const char* filepath);
	//bool loadAssimp();
};

