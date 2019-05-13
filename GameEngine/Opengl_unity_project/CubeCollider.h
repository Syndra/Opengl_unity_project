/*
Collider의 중심점은 언제나 GameObject의 중심점과 같습니다.
따라서, GameObject의 Mesh 생성시, Vertex의 x,y,z vector의 최대 최솟값의 중간값을
기반으로 중심점을 생성해야만 합니다.
*/
#pragma once

#include <glm\glm.hpp>
#include "Collider.h"

class Transform;
class Renderer;

class CubeCollider : public Collider
{
public:

	Transform * transform;
	Renderer * renderer;

	CubeCollider(Transform *transform, Renderer *renderer);
	~CubeCollider();

	void setCollider();
	void setCollider(glm::vec3 colliderSize);
	bool isCollided(Collider * targetCollider);
};

