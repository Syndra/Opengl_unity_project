#pragma once
#include <glm\glm.hpp>
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <glm\gtc\matrix_transform.hpp>

class control {
public:
	// position
	glm::vec3 position = glm::vec3(0, 0, 5);
	// horizontal angle : toward -Z
	float horizontalAngle = 3.14f;
	// vertical angle : 0, look at the horizon
	float verticalAngle = 0.0f;
	// Initial Field of View
	float initialFoV = 45.0f;

	float speed = 3.0f; // 3 units / second
	float mouseSpeed = 0.005f;

	glm::mat4 projection_matrix;
	glm::mat4 view_matrix;
	glm::mat4 model_matrix;

	void computeMatricesFromInputs(GLFWwindow *window, GLfloat deltaTime);
	static glm::mat4 get_view_matrix(GLFWwindow *window, GLfloat deltaTime);
	glm::mat4 get_projection_matrix();
	void wheel_callback(GLFWwindow *window, float y_pos);
};