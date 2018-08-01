#include "Scene.h"
#include "Timer.h"
#include "Window.h"
#include "Renderer.h"
#include "Updatable.h"
#include "MyObject.h"
#include "myGamemanager.h"
#include "Light.h"
#include "Shader.h"
#include "SceneObjectSorter.h"

std::vector<Renderer*> Scene::renderer;
std::vector<Updatable*> Scene::updatable;
std::vector<Light*> Scene::light;
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
	Scene::light = std::vector<Light*>();

	timer = new Timer();
	camera_in_scene = new Camera();
	
	Shader::init_all_shaders();

	gamemanager = new myGamemanager();
}

void Scene::start_scene()
{
	for (int it = 0; it < Scene::updatable.size(); it++)
	{
		Scene::updatable.at(it)->start();
	}

	//call render for all object in vector.
	while (glfwGetKey(Window::window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(Window::window) == 0)
	{
		glfwSetCursorPos(Window::window, 1024 / 2, 768 / 2);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);
		//set default background color.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(1,1,1,1);

		gamemanager->run();

		timer->tick();

		//glDisable(GL_BLEND);
		for (int it = 0; it < Scene::light.size(); it++)
		{
			Scene::light.at(it)->refresh();
		}

		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
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

