#pragma once
#include <vector>
#include "Tetris_block.h"
#include "BaseObject.h"
#include <glm\glm.hpp>

class Camera;

class Block : public Tetris_block
{
public:

	GLuint programID; // Should be in windows or some higher class. For test.

	GLfloat speed = 5.f;

	glm::vec3 position = glm::vec3(0,0,0);

	std::vector <Tetris_block *> block;

	bool isdead = false;

	Block();
	~Block();

	glm::mat4 compute_model_matrix();

	void render(Camera *camera);
	void update();
	void position_update();
};
