#include "Scene.h"
#include "Timer.h"
#include "Tetris_block.h"
#include "Block.h"
#include "Window.h"
#include "Renderer.h"
#include "Updatable.h"

std::vector<Renderer*> Scene::renderer;
std::vector<Updatable*> Scene::updatable;

Scene::Scene()
{
	this->init_scene();
	gamemanager = new Gamemanager();
}

Scene::Scene(Gamemanager * gamemanager)
{
	this->init_scene();
	this->gamemanager = gamemanager;
}


Scene::~Scene()
{
}

void Scene::init_scene()
{
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	//Init default camera.
	this->window = Window::window;
	this->camera_in_scene = new Camera();
	this->camera_in_scene->position.z = 50;

	timer = new Timer();

	//주석달아야됨
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	for (int it = 0; it < Scene::updatable.size(); it++)
	{
		Scene::updatable.at(it)->start();
	}
}

void Scene::start_scene()
{
	//call render for all object in vector.
	while (current_in_window && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0)
	{
		//set default background color.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		timer->tick();
		gamemanager->run();

		for (int it = 0; it < Scene::renderer.size(); it++)
		{
			Scene::renderer.at(it)->render(camera_in_scene);
		}

		for (int it = 0; it < Scene::updatable.size(); it++)
		{
			Scene::updatable.at(it)->update();
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

