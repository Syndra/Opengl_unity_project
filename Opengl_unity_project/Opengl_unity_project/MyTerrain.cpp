#include "MyTerrain.h"
#include "Terrain.h"
#include "Scene.h"
#include "Shader.h"
#include "Mesh.h"
#include <ctime>

MyTerrain::MyTerrain()
{
	this->transform = new Transform(-100, -50, -100);
	this->transform->scale = 1;
	this->renderer = new Renderer(this->transform);

	//this->terrain = new Terrain("obj/index.jpg", 225, 225, 0.3);
	this->terrain = new Terrain(7, 1, 0.005);
	this->renderer->set_model(this->terrain);

	Scene::renderer.push_back(this->renderer);

	this->renderer->shader = Shader::NoTextureShader;
	this->terrain->set_Transparency(0.6f);
	this->terrain->set_Color(glm::vec3(0,0,0.7f));
	this->terrain->meshes.at(0).set_texture("engineflare1.jpg");
	//this->renderer->shader = Shader::BasicLightShader;

	GLuint temp;
	std::vector <GLfloat> rands;

	srand(time(0));

	for (int  i = 0 ; i < this->terrain->meshes.at(0).vertices.size(); i++) 
	{
		int rn = rand() % 2000;
		rands.push_back(rn * 0.001);
	}

	glBindVertexArray(this->terrain->meshes.at(0).VAO);
	glGenBuffers(1, &temp);
	glBindBuffer(GL_ARRAY_BUFFER, temp);
	glBufferData(GL_ARRAY_BUFFER, rands.size() * sizeof(GLfloat), &rands[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(10);
	glVertexAttribPointer(10, 1, GL_FLOAT, GL_FALSE, sizeof(GLfloat), (GLvoid *)0);
}


MyTerrain::~MyTerrain()
{
}

void MyTerrain::set_terrain(const char * path, int width, int length)
{
	terrain = new Terrain(path, width, length, 0.25);
	this->renderer->set_model(terrain);
}
