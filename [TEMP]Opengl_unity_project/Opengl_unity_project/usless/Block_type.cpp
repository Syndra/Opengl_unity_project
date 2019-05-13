#include "Block_type.h"

glm::vec3 Block_type::type[5][4] = {
{ glm::vec3(0,0,0), glm::vec3(0,1,0),glm::vec3(0,2,0),glm::vec3(0,3,0) },
{ glm::vec3(0,0,0), glm::vec3(1,0,0),glm::vec3(1,1,0),glm::vec3(0,1,0) },
{ glm::vec3(0,0,0), glm::vec3(1,0,0),glm::vec3(1,1,0),glm::vec3(1,2,0) },
{ glm::vec3(0,0,0), glm::vec3(1,0,0),glm::vec3(0,1,0),glm::vec3(0,2,0) },
{ glm::vec3(0,0,0), glm::vec3(1,0,0),glm::vec3(1,1,0),glm::vec3(2,0,0) }
};

glm::vec3 * Block_type::get_random()
{
	return Block_type::type[std::rand() % 5];
}
