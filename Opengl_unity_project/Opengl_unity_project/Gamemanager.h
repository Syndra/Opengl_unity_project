#pragma once
#include "Tetris_block.h"

class Gamemanager
{
public:

	bool block_location_map[20][8];

	Gamemanager();
	~Gamemanager();

	void init_location_map();
};

