#include "Block.h"
#include "Window.h"
#include "Timer.h"
#include "Camera.h"
#include "Shader.h"
#include "Block_type.h"
#include <random>
#include <ctime>

Block::Block()
{
	std::srand(std::time(nullptr));

	glm::vec3* type = Block_type::type[std::rand()%5];
	for (int loop = 0 ; loop < 4; loop ++) 
	{
		Tetris_block *base = new Tetris_block();
		base->set_mesh();
		base->position += type[loop];
		block.push_back(base);
	}
}


glm::mat4 Block::compute_model_matrix()
{
	return glm::translate(glm::mat4(1.0f), this->position);
}

Block::~Block()
{
}

void Block::render(Camera * camera)
{
	for (Tetris_block *elem : block) 
	{
		elem->render(camera);
	}
}

void Block::update()
{
	if (!isdead) {
		this->position.y -= Timer::deltatime * speed;
		this->position_update();
	}
}

void Block::position_update()
{
	for (Tetris_block *elem : block)
	{
		elem->position += position;
	}
	position = glm::vec3(0,0,0);
}
