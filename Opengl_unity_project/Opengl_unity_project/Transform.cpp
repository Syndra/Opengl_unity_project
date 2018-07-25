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
	this->euler_angle = glm::vec3(0, 0, 0);
}


Transform::~Transform()
{
}

glm::vec3 Transform::get_Lookat()
{
	glm::quat Temp_Quat = glm::quat(euler_angle);
	glm::mat4 Rotation = glm::mat4_cast(Temp_Quat);

	glm::vec3 temp = glm::vec3(Rotation * glm::vec4(0, 0, 1, 0));

	return position-temp;
}

glm::vec3 Transform::get_dir()
{
	glm::quat Temp_Quat = glm::quat(euler_angle);
	glm::mat4 Rotation = glm::mat4_cast(Temp_Quat);

	glm::vec3 temp = glm::vec3(Rotation * glm::vec4(0, 0, 1, 0));

	return temp;
}

glm::mat4 Transform::get_rotationMat()
{
	glm::quat Temp_Quat = glm::quat(euler_angle);
	glm::mat4 Rotation = glm::mat4_cast(Temp_Quat);
	return Rotation;
}
