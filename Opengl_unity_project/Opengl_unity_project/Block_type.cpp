#include "Block_type.h"

glm::vec3 Block_type::type[5][4] = {
{ glm::vec3(0,0,0), glm::vec3(0,2,0),glm::vec3(0,4,0),glm::vec3(0,6,0) },
{ glm::vec3(0,0,0), glm::vec3(2,0,0),glm::vec3(2,2,0),glm::vec3(0,2,0) },
{ glm::vec3(0,0,0), glm::vec3(2,0,0),glm::vec3(2,2,0),glm::vec3(2,4,0) },
{ glm::vec3(0,0,0), glm::vec3(2,0,0),glm::vec3(0,2,0),glm::vec3(0,4,0) },
{ glm::vec3(0,0,0), glm::vec3(2,0,0),glm::vec3(2,2,0),glm::vec3(4,0,0) }
};

glm::vec3 * Block_type::get_random()
{
	return Block_type::type[std::rand() % 5];
}
