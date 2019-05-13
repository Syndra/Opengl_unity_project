#pragma once
class Updatable
{
public:
	Updatable();
	~Updatable();

	virtual void update();
	void start();
};

