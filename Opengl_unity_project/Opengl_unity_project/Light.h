#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Light
{
public:

	float AmbientLight[4] = { 0.0f, 0.0f, 0.2f, 0.0f };         //ÁÖº¯±¤
	float DiffuseLight[4] = { 0.5f, 0.5f, 0.5f, 0.0f };          //ºÐ»ê±¤
	float SpecularLight[4] = { 0.5f, 0.5f, 0.5f, 0.0f };        //¹æ»ç±¤
	float LightPosition[4] = { 10.0f, 10.0f, 40.0f, 1.0f };  //Á¶¸í À§Ä¡
	float specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	Light();
	~Light();

	void init_light();
};

