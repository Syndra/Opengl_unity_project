#pragma once
#include <vector>


class MyObject;

class myGamemanager
{
public:

	std::vector<MyObject *> cubes;

	myGamemanager();
	~myGamemanager();

	void run();
};

