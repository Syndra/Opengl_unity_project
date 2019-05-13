#pragma once

#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "FreeImage.h"

class TextureLoader
{
public:

	static GLuint CreateTexture(char const* filename);

	TextureLoader();
	~TextureLoader();
};

