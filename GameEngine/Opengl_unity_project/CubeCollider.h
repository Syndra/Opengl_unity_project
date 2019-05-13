/*
Collider�� �߽����� ������ GameObject�� �߽����� �����ϴ�.
����, GameObject�� Mesh ������, Vertex�� x,y,z vector�� �ִ� �ּڰ��� �߰�����
������� �߽����� �����ؾ߸� �մϴ�.
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

