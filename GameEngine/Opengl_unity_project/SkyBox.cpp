#include "SkyBox.h"
#include "Scene.h"
#include "Mesh.h"
#include "Model.h"
#include "Shader.h"
#include "Transform.h"
#include <iostream>


SkyBox::SkyBox()
{
	this->transform = Scene::camera_in_scene->transform;
	this->transform->scale = Scene::camera_in_scene->far / (1.3f * sqrt(2));
	this->renderer = new Renderer(this->transform);

	this->model = new Model("obj/skybox.obj");

	this->renderer->set_model(this->model);
	this->renderer->set_ShadowTarget(false);

	this->updatable = new Updatable();

	std::reverse(Scene::renderer.begin(), Scene::renderer.end());
	Scene::renderer.push_back(this->renderer);
	std::reverse(Scene::renderer.begin(), Scene::renderer.end());
	Scene::updatable.push_back(this->updatable);

	//this->renderer->shader = Shader::NoTextureShader;
	//this->renderer->shader = Shader::BasicLightShader;
	this->renderer->shader = Shader::skybox;

	usecubemap();
	glUseProgram(Shader::skybox);
	glActiveTexture(GL_TEXTURE19);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemap->textureID);
	glUniform1i(glGetUniformLocation(Shader::skybox, "cubeMap"), 19);
}


SkyBox::~SkyBox()
{
}

void SkyBox::usecubemap()
{
	std::vector<std::string> faces
	{
		"obj/TropicalSunnyDay_px.jpg", //r 
		"obj/TropicalSunnyDay_nx.jpg", //l
		"obj/TropicalSunnyDay_py.jpg", //t
		"obj/TropicalSunnyDay_ny.jpg", //d
		"obj/TropicalSunnyDay_pz.jpg", //f
		"obj/TropicalSunnyDay_nz.jpg" //b
	};
	cubemap = new CubeMap(faces);
}
