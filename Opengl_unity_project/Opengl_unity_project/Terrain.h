#pragma once

#include <vector>
#include <gl\glew.h>
#include <glm\glm.hpp>
#include <SOIL\SOIL.h>
#include "Transform.h"
#include "Model.h"

struct Vertex;
struct Texture;

class Terrain : public Model
{
public:

	const char * path;

	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture> textures;

	int width;
	int length;

	float height_degree;

	GLuint TextureID;

	glm::vec3 color = glm::vec3(0, 1, 1);

	Terrain(const char *path, int width, int length, float degree);
	~Terrain();

	void set_terrain(const char * path);
	void loadfromHeightMap(const char * path);
};

