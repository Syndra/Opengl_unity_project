#include "Terrain.h"

Terrain::Terrain(const char *path, int width, int lenght, float degree)
{
	this->width = width;
	this->length = lenght;
	this->height_degree = degree;
	set_terrain(path);
	Mesh mesh(this->vertices, this->indices, this->textures);
	this->meshes.push_back(mesh);
}

Terrain::~Terrain()
{
}

void Terrain::set_terrain(const char * path)
{
	loadfromHeightMap(path);
}

void Terrain::loadfromHeightMap(const char * path)
{
	unsigned char *heightMap = SOIL_load_image(path, &width, &length, 0, SOIL_LOAD_L);
	
	this->path = path;

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < length; y++)
		{
			Vertex vertex;
			glm::vec3 vector_position;
			vector_position.x = x;
			vector_position.y = heightMap[x + y * width];
			vector_position.z = y;

			vertex.Position = vector_position;

			glm::vec3 vector_normal;
			if (x == 0 || y == 0) 
			{
				vector_normal = glm::vec3(0,0,0);
			}
			else 
			{
				vector_normal = glm::normalize(glm::vec3(
					2*(heightMap[x+1 + y * width] - heightMap[x-1 + y * width]),
					-4,
					2*(heightMap[x + (y+1) * width] - heightMap[x + (y-1) * width])
					));
			}

			vertex.Normal = vector_normal;

			vertices.push_back(vertex);
		}
	}
	for (int x = 0; x < width - 1; x++)
	{
		for (int y = 0; y < length - 1; y++)
		{
			indices.push_back(x + y * width);
			indices.push_back(x + 1 + y * width);
			indices.push_back(x + (y+1) * width);

			indices.push_back(x+1 + (y + 1) * width);
			indices.push_back(x + (y+1) * width);
			indices.push_back(x+1 + y * width);		
		}
	}
}
