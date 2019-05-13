#pragma once
class BaseObject
{
public:
	BaseObject();
	~BaseObject();

	virtual void start();
	virtual void update();
};

