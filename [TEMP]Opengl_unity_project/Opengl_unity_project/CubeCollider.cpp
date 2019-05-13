#include "CubeCollider.h"
#include "Transform.h"
#include "Renderer.h"


CubeCollider::CubeCollider(Transform *transform, Renderer *renderer)
{
	this->transform = transform;
	this->renderer = renderer;
}


CubeCollider::~CubeCollider()
{
}

void CubeCollider::setCollider()
{
}

void CubeCollider::setCollider(glm::vec3 colliderSize)
{
}

bool CubeCollider::isCollided(Collider * targetCollider)
{
	return false;
}
