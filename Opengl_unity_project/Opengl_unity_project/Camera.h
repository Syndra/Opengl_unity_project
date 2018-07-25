#pragma once
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

class Transform;
class CameraUpdatable;
class Light;

class Camera
{
public:	
	//Components
	Transform *transform;
	CameraUpdatable *updatable;

	float fovy;
	float aspect;
	float near;
	float far;

	//For test
	//Light *cameraLight;

	Camera();
	~Camera();
	glm::mat4 get_projection_matrix();
	glm::mat4 get_view_matrix();
	//void update();
};

