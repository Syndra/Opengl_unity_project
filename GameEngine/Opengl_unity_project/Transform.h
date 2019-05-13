#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/common.hpp>

using namespace std;

class Transform
{
public:

	glm::vec3 position;

	glm::vec3 euler_angle;

	glm::vec3 lookat = glm::vec3(0,0,1);

	glm::vec3 up = glm::vec3(0, 1, 0);

	glm::vec3 dir;

	float scale = 1.f;

	Transform(glm::vec3 position);
	Transform();
	Transform(float x, float y, float z);
	~Transform();

	glm::vec3 get_Lookat();
	glm::vec3 get_dir();
	glm::mat4 get_rotationMat();
};

