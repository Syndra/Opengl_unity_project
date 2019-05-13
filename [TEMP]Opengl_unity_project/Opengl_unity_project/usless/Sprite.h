#pragma once

#include <vector>
#include <glm/glm.hpp>

class Sprite
{
public:

	const char * path;
	std::vector <glm::vec3> vertices;
	std::vector <glm::vec2> uvs;
	std::vector <glm::vec3> normals;

	Sprite();
	~Sprite();

	bool loadFile(char *filepath);
};

