#include "Transform.h"



Transform::Transform(glm::vec3 position)
{
	this->position = position;
}

Transform::Transform(float x, float y, float z)
{
	this->position = glm::vec3(x,y,z);
}

Transform::Transform()
{
	this->position = glm::vec3(0, 0, 0);
}


Transform::~Transform()
{
}
