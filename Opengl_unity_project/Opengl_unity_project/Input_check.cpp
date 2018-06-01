#include "Input_check.h"
#include <iostream>

Input_check::Input_check()
{
}


Input_check::~Input_check()
{
}

void Input_check::input_check(std::vector <BaseObject *> baseobjects)
{
	for (int i = 0; i < baseobjects.size() ; i++) 
	{
		baseobjects.at(i)->update();
	}
}

