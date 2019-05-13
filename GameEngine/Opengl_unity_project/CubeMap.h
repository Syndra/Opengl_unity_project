#pragma once

#include <GL/glew.h>
#include <SOIL/SOIL.h>
#include <vector>

class CubeMap
{
public:

	unsigned int textureID;

	CubeMap(std::vector<std::string> faces);
	~CubeMap();
};

