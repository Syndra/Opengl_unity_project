#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <FreeImage.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "Vertex_data.h"
#include "control.h"

GLuint LoadShaders(const char *, const char *);
GLuint CreateTexture(char const* );