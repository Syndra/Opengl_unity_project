#pragma once
#include <vector>


class MyObject;
class MyLightSource;

class myGamemanager
{
public:

	std::vector<MyObject *> cubes;
	MyLightSource *light;
	MyLightSource *light1;

	myGamemanager();
	~myGamemanager();

	void run();
};

