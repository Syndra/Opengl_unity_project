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
	block_type = std::rand() % 5;
	glm::vec3 *type = Block_type::type[block_type];
	for (int loop = 0 ; loop < 4; loop ++) 
	{
		Tetris_block *base = new Tetris_block();
		base->set_mesh();
		base->position += type[loop] + position;
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
	this->position_update();
}

void Block::position_update()
{
	int i = 0;
	for (Tetris_block *elem : block)
	{
		elem->position = Block_type::type[block_type][i] + position;
		i++;
	}
}

