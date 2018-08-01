#pragma once

#include <vector>
#include <gl\glew.h>
#include <glm\glm.hpp>
#include <SOIL\SOIL.h>
#include "Transform.h"
#include "Model.h"

struct Vertex;
struct Texture;

class Terrain : public Model
{
public:

	const char * path;
	unsigned char *heightMap;

	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture> textures;

	int width;
	int length;

	float height_degree;

	GLuint TextureID;

	//
	int max;
	float scale;
	int maximum_height;
	bool isAutoGen = false;
	float **genHeightMap;

	Terrain(const char *path, int width, int length, float degree);
	Terrain(int detail, int maximum_height, float scale);
	~Terrain();

	void set_terrain(const char * path);
	void loadfromHeightMap(const char * path);
	void init_array(const char *path);
	char get_height(int index);
	void gen_HeightMap();
	void divide(int size);
	void square(int x, int y, int size, int dis);
	void diamond(int x, int y, int size, int dis);
};

