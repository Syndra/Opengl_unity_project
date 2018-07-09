#pragma once
#include <vector>


class MyObject;
class MyLightSource;

class myGamemanager
{
public:

	std::vector<MyObject *> cubes;
	MyLightSource *light;

	myGamemanager();
	~myGamemanager();

	void run();
};

