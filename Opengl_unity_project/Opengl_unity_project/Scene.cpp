#include "Scene.h"
#include "Timer.h"
#include "Window.h"
#include "Renderer.h"
#include "Updatable.h"
#include "MyObject.h"
#include "myGamemanager.h"
#include "Light.h"

std::vector<Renderer*> Scene::renderer;
std::vector<Updatable*> Scene::updatable;
Camera *Scene::camera_in_scene;

Scene::Scene()
{
	this->init_scene();
	this->start_scene();
}

Scene::~Scene()
{
}

void Scene::init_scene()
{
	glfwSetInputMode(Window::window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	Scene::renderer = std::vector<Renderer*>();
	Scene::updatable = std::vector<Updatable*>();

	timer = new Timer();
	camera_in_scene = new Camera();

	gamemanager = new myGamemanager();

	/*light = new Light();
	light->init_light();*/
}

void Scene::start_scene()
{
	glfwSetCursorPos(Window::window, 1024 / 2, 768 / 2);
	//call render for all object in vector.
	while (glfwGetKey(Window::window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(Window::window) == 0)
	{
		//set default background color.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		gamemanager->run();

		timer->tick();

		for (int it = 0; it < Scene::renderer.size(); it++)
		{
			Scene::renderer.at(it)->render(camera_in_scene);
		}

		for (int it = 0; it < Scene::updatable.size(); it++)
		{
			Scene::updatable.at(it)->update();
		}

		glfwSwapBuffers(Window::window);
		glfwPollEvents();
	}
}

