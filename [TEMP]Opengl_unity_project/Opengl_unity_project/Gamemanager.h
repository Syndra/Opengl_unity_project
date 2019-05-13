#pragma once
#include <vector>

#define MAX_COL 11
#define MAX_ROW 30
#define USER_COL_START 1
#define USER_COL_END 10
#define USER_ROW_START 1
#define USER_ROW_END 19

class Block;
class Tetris_block;

class Gamemanager
{
public:

	std::vector<Tetris_block*> block_in_game;
	Block* focused_block;

	bool block_location_map[MAX_COL][MAX_ROW];

	float speed = 5.f;

	Gamemanager();
	~Gamemanager();

	void init_location_map();
	void process_block_down();
	bool is_able_to_move_down();
	void process_move_side();
	void run_logic_check_line();
	void process_create_block();
	void run();
	void map_test();
	void process_refresh_block();
};

