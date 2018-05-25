#include "Scene.h"



Scene::Scene(GLFWwindow *window)
{
	this->init_scene(window);

	//Generate object. set mesh.
	object *triangle1 = new object();
	triangle1->set_mesh();

	//Push objects to vector.
	object_in_scene.push_back(triangle1);

	//render all objects in windows.
	render_scene();
}


Scene::~Scene()
{
}

void Scene::init_scene(GLFWwindow *window)
{
	//Init default camera.
	this->window = window;
	this->camera_in_scene = new Camera();

	//주석달아야됨
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}

void Scene::render_scene()
{
	//call render for all object in vector.
	while (current_in_window && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0)
	{
		//set default background color.
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (int it = 0; it < this->object_in_scene.size(); it++)
		{
			this->object_in_scene.at(it)->render_object(this->camera_in_scene);
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

