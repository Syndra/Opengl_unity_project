#include "Terrain.h"
#include <ctime>
#include <iostream>

Terrain::Terrain(const char *path, int width, int lenght, float degree)
{
	this->width = width;
	this->length = lenght;
	this->height_degree = degree;
	set_terrain(path);
	Mesh mesh(this->vertices, this->indices, this->textures);
	this->meshes.push_back(mesh);
}

Terrain::Terrain(int detail, int maximum_height, float scale)
{
	isAutoGen = true;
	this->maximum_height = maximum_height + 1;
	this->width = pow(2, detail) + 1;
	this->max = this->width - 1;
	this->scale = scale;
	this->length = this->width;
	gen_HeightMap();
	Mesh mesh(this->vertices, this->indices, this->textures);
	this->meshes.push_back(mesh);
}

Terrain::~Terrain()
{
}

void Terrain::set_terrain(const char * path)
{
	this->path = path;
	init_array(path);
	loadfromHeightMap(path);
}

void Terrain::loadfromHeightMap(const char * path)
{
	for (int x = 0; x < width ; x++)
	{
		for (int y = 0; y < length ; y++)
		{
			Vertex vertex;
			glm::vec3 vector_position;
			vector_position.x = x;
			vector_position.y = get_height(x + y * width);
			vector_position.z = y;

			vertex.Position = vector_position;

			glm::vec2 vector_texcoord;
			vector_texcoord.x = (float)x/width;
			vector_texcoord.y = (float)y/length;

			vertex.TexCoords = vector_texcoord;

			glm::vec3 vector_normal;
			if (x == 0 || y == 0 || x == width -1 || y == length - 1) 
			{
				vector_normal = glm::vec3(0,0,0);
			}
			else 
			{
				vector_normal = glm::normalize(glm::vec3(
					2*(get_height(x+1 + y * width) - get_height((x-1) + y * width)),
					-4,
					2*(get_height(x + (y+1) * width) - get_height(x + (y-1) * width))
					));
			}

			vertex.Normal = vector_normal;

			vertices.push_back(vertex);
		}
	}
	for (int x = 0; x < width -1; x++)
	{
		for (int y = 0; y < length - 1; y++)
		{
			indices.push_back(x + y * width);
			indices.push_back(x + 1 + y * width);
			indices.push_back(x + (y + 1) * width);

			indices.push_back(x + 1 + y * width);
			indices.push_back((x + 1)+ (y + 1) * width);
			indices.push_back(x + (y + 1) * width);
		}
	}
}

void Terrain::init_array(const char *path)
{
	heightMap = SOIL_load_image(path, &width, &length, 0, SOIL_LOAD_L);
}

char Terrain::get_height(int index)
{
	return heightMap[index] * height_degree;
}

void Terrain::gen_HeightMap()
{
	int x = width;
	genHeightMap = new float*[x];
	for (int i = 0; i < x; i++)
	{
		genHeightMap[i] = new float[x];
	}

	srand((unsigned int)time(0));

	//set random height each side point.
	genHeightMap[0][0] = rand() % maximum_height;
	genHeightMap[0][max] = rand() % maximum_height;
	genHeightMap[max][0] = rand() % maximum_height;
	genHeightMap[max][max] = rand() % maximum_height;

	divide(max);

	for (int x = 0; x < max ; x++)
	{
		for (int y = 0; y < max ; y++)
		{
			Vertex vertex;
			glm::vec3 vector_position;
			vector_position.x = x;
			vector_position.y = genHeightMap[x][y];
			vector_position.z = y;

			vertex.Position = vector_position;

			glm::vec2 vector_texcoord;
			vector_texcoord.x = (float)x / width;
			vector_texcoord.y = (float)y / width;

			vertex.TexCoords = vector_texcoord;

			glm::vec3 vector_normal;
			if (x == 0 || y == 0)
			{
				vector_normal = glm::vec3(0, 0, 0);
			}
			else
			{
				vector_normal = glm::normalize(glm::vec3(
					2 * (genHeightMap[x+1][y] - genHeightMap[x-1][y]),
					-4,
					2 * (genHeightMap[x][y+1] - genHeightMap[x][y-1])
				));
			}

			vertex.Normal = vector_normal;

			vertices.push_back(vertex);
		}
	}
	for (int x = 0; x < max - 1; x++)
	{
		for (int y = 0; y < max - 1; y++)
		{
			indices.push_back((unsigned int)(x * max + y ));
			indices.push_back((unsigned int)(x * max + y + 1));
			indices.push_back((unsigned int)((x+1) * max  + y));

			indices.push_back((unsigned int)(x * max + y + 1));
			indices.push_back((unsigned int)((x + 1) * max + y + 1));
			indices.push_back((unsigned int)((x + 1) * max + y));
		}
	}
}

void Terrain::divide(int size)
{
	int x = 0, y = 0;
	int half = size / 2;
	float scale = size * this->scale;
	if (half < 1) return;

	//square
	for (y = half; y < max; y += size)
	{
		for (x = half; x < max; x += size)
		{
			square(x, y, half, rand() % maximum_height * scale * 2 - scale);
		}
	}
	//diamond
	for (y = 0; y <= max; y += half)
	{
		for (x = (y + half) % size; x <= max; x += size)
		{
			diamond(x, y, half, rand() % maximum_height * scale * 2 - scale);
		}
	}
	divide(size / 2);
}

void Terrain::square(int x, int y, int size, int dis)
{
	float ave = (genHeightMap[x - size][y - size]
		+ genHeightMap[x + size][y - size]
		+ genHeightMap[x - size][y + size]
		+ genHeightMap[x + size][y + size]) / 4;
	genHeightMap[x][y] = ave + dis;
}

void Terrain::diamond(int x, int y, int size, int dis)
{
	float u, d, r, l;
	l = (x - size < 0) ? genHeightMap[x + size][y] : genHeightMap[x - size][y];
	r = (x + size > max) ? genHeightMap[x - size][y] : genHeightMap[x + size][y];
	u = (y - size < 0) ? genHeightMap[x][y + size] : genHeightMap[x][y - size];
	d = (y + size > max) ? genHeightMap[x][y - size] : genHeightMap[x][y + size];

	float ave = (l + r + d + u) / 4;
	genHeightMap[x][y] = ave + dis;
}

