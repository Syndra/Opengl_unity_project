#include "Gamemanager.h"
#include "Timer.h"
#include "Block.h"
#include "Block_type.h"
#include <iostream>
#include "Window.h"

Gamemanager::Gamemanager()
{
	this->init_location_map(); 
}


Gamemanager::~Gamemanager()
{

}

void Gamemanager::init_location_map()
{
	int i, j;
	for (i = 0; i < MAX_COL; i++) 
	{
		for (j = 0; j < MAX_ROW; j++) 
		{
			if (j == 0 || i == 0 || i == MAX_COL - 1)
				this->block_location_map[i][j] = true;
			else
				this->block_location_map[i][j] = false;
		}
	}
	process_refresh_block();
}

void Gamemanager::process_block_down()
{
	focused_block->position.y -= Timer::deltatime * speed;
}

bool Gamemanager::is_able_to_move_down()
{
	if (focused_block->position.y < USER_ROW_START)
	{
		focused_block->position.y = USER_ROW_START;
		return false;
	}
	int type_num = focused_block->block_type;
	int x, y;

	for (int it = 0; it < 4; it ++) 
	{
		x = Block_type::type[type_num][it].x + focused_block->position.x;
		y = Block_type::type[type_num][it].y + focused_block->position.y;
		if (block_location_map[x][y-1])
		{
			focused_block->position.y = y;
			return false;
		}
	}
	return true;
}

void Gamemanager::process_move_side()
{
	bool r_flag = true, l_flag = true;
	for (int it = 0; it < 4; it++)
	{
		int x = Block_type::type[focused_block->block_type][it].x + focused_block->position.x;
		int y = Block_type::type[focused_block->block_type][it].y + focused_block->position.y;
		l_flag *= !block_location_map[x - 1][y - 1];
		r_flag *= !block_location_map[x + 1][y - 1];
	}

	if (glfwGetKey(Window::window, GLFW_KEY_A) == GLFW_PRESS 
		&& l_flag) {
		focused_block->position.x -= 1;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_D) == GLFW_PRESS
		&& r_flag) {
		focused_block->position.x += 1;
	}
}

void Gamemanager::run_logic_check_line()
{
	int i, j, k, r;
	bool flag = true;
	for (j = USER_ROW_START; j < USER_ROW_END; j++) 
	{
		flag = true;
		for (i = USER_COL_START; i < USER_COL_END; i++) 
		{
			flag *= block_location_map[i][j];
		}
		if (flag) 
		{
			for (i = USER_COL_START; i < USER_COL_END; i++)
			{
				block_location_map[i][j] = false;
			}
			for (k = j; k < USER_ROW_END; k++) 
			{
				for (r = USER_COL_START; r < USER_COL_END; r++) 
				{
					block_location_map[r][k] = block_location_map[r][k + 1];
				}
			}
			std::cout << "clear";
		}
	}
}

void Gamemanager::process_create_block()
{ 
	Block *block = new Block();
	block->position.y = 19;
	block->position.x = 3;
	focused_block = block;
	block->set_mesh();
	this->map_test();
}

void Gamemanager::run()
{
	//if game is over. out.

	if (focused_block == NULL)
		process_create_block();

	process_move_side();

	if(is_able_to_move_down())
		process_block_down();
	else 
	{
		//do some logics on boolean maps.
		int x, y;
		for (int it = 0; it < 4; it++)
		{
			x = Block_type::type[focused_block->block_type][it].x + focused_block->position.x;
			y = Block_type::type[focused_block->block_type][it].y + focused_block->position.y;
			block_location_map[x][y] = true;
		}
		run_logic_check_line();
		process_refresh_block();
		process_create_block();
	}
}

void Gamemanager::map_test()
{
	int i, j;
	for (j = USER_ROW_END; j > -1; j--)
	{
		for (i = 0; i < USER_COL_END+1; i++)
		{
			if (this->block_location_map[i][j])
				std::cout << 1;
			else
				std::cout << 0;
		}
		std::cout << "\n";
	}
}

void Gamemanager::process_refresh_block()
{
	block_in_game.clear();

	int i, j;
	for (i = 0; i < MAX_COL; i++)
	{
		for (j = 0; j < USER_ROW_END; j++)
		{
			if (this->block_location_map[i][j]) 
			{
				Tetris_block *block = new Tetris_block();
				block->set_mesh();
				block->position = glm::vec3(i,j,0);
				block_in_game.push_back(block);
			}
		}
	}
}

