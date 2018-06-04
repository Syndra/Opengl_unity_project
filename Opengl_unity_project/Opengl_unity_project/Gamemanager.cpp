#include "Gamemanager.h"



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
	for (i = 0; i<20;i++) 
	{
		for (j = 0; j<8;j++) 
		{
			this->block_location_map[i][j] = false;
		}
	}
}
