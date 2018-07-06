#include "Scene.h"
#include "Timer.h"
#include "Window.h"
#include "Renderer.h"
#include "Updatable.h"
#include "MyObject.h"

std::vector<Renderer*> Scene::renderer;
std::vector<Updatable*> Scene::updatable;

Scene::Scene()
{
	this->init_scene();
	MyObject *cube = new MyObject();
	MyObject *cube1 = new MyObject();
	MyObject *cube2 = new MyObject();
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
}

void Scene::start_scene()
{
	//call render for all object in vector.
	while (glfwGetKey(Window::window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(Window::window) == 0)
	{
		//set default background color.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.3f, 0.4f, 0.1f, 0.5f);
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

