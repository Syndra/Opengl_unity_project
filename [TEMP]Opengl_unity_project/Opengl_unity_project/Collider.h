#pragma once

class Collider
{
public:

	Collider();
	~Collider();

	virtual bool isCollided(Collider * targetCollider);
	virtual void setCollider();
};

