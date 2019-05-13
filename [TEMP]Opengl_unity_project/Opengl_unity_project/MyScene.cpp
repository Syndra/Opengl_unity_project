#include "MyScene.h"
#include "MyObject.h"
#include "Window.h"
#include "MyObject.h"
#include "Transform.h"
#include "Renderer.h"
#include "Updatable.h"

std::vector<Renderer*> MyScene::renderer;
std::vector<Updatable*> MyScene::updatable;

MyScene::MyScene()
{
	this->init_scene();
	cube = new MyObject();
	this->start_scene();
}


MyScene::~MyScene()
{
}

void MyScene::init_scene()
{
	glfwSetInputMode(Window::window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	MyScene::renderer = std::vector<Renderer*>();
	MyScene::updatable = std::vector<Updatable*>();

	timer = new Timer();
	camera_in_scene = new Camera();
}

void MyScene::start_scene()
{
	//call render for all object in vector.
	while (glfwGetKey(Window::window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(Window::window) == 0)
	{
		//set default background color.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		timer->tick();

		for (int it = 0; it < MyScene::renderer.size(); it++)
		{
			MyScene::renderer.at(it)->render(camera_in_scene);
		}

		for (int it = 0; it < MyScene::updatable.size(); it++)
		{
			std::cout << "sd";
			MyScene::updatable.at(it)->update();
		}
		glfwSwapBuffers(Window::window);
		glfwPollEvents();
	}
}
