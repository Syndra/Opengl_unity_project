#pragma once

#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "FreeImage.h"

class Texture
{
public:

	static GLuint CreateTexture(char const* filename);

	Texture();
	~Texture();
};

