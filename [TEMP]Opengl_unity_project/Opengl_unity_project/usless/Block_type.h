#pragma once
#include <glm\glm.hpp>
class Block_type
{
public:
	static glm::vec3 type[5][4];
	static glm::vec3* get_random();
};