#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Light
{
public:

	float AmbientLight[4] = { 0.0f, 0.0f, 0.2f, 0.0f };         //�ֺ���
	float DiffuseLight[4] = { 0.5f, 0.5f, 0.5f, 0.0f };          //�л걤
	float SpecularLight[4] = { 0.5f, 0.5f, 0.5f, 0.0f };        //��籤
	float LightPosition[4] = { 10.0f, 10.0f, 40.0f, 1.0f };  //���� ��ġ
	float specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	Light();
	~Light();

	void init_light();
};

