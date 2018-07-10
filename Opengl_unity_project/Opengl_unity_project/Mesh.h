#pragma once
#include <gl\glew.h>
#include <glm\glm.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>

class Mesh
{
public:

	const char * path;

	std::vector<unsigned short> indices;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	GLuint Texture;

	glm::vec3 color = glm::vec3(1,1,1);

	Mesh(const char *meshName);
	Mesh();
	~Mesh();

	void set_texture(const char* filepath);
	bool loadAssimp();
	void init_mesh();
};

