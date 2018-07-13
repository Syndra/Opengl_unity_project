#pragma once
#include <vector>


class MyObject;
class MyLightSource;

class myGamemanager
{
public:

	std::vector<MyObject *> cubes;
	MyLightSource *sunlight;
	MyLightSource *pointedlight;

	myGamemanager();
	~myGamemanager();

	void run();
};

