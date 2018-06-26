#include "Scene.h"
#include "Timer.h"
#include "Tetris_block.h"
#include "Block.h"

Scene::Scene(GLFWwindow *window)
{
	this->init_scene(window);

	gamemanager = new Gamemanager();

	//Generate object. set mesh.
	//Block *block = new Block();
	//block->set_mesh();

	//Push objects to vector.
	//object_in_scene.push_back(block);
	//object_render.push_back(block);

	//render all objects in windows.
	render_scene();
}


Scene::~Scene()
{
}

void Scene::init_scene(GLFWwindow *window)
{
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	//Init default camera.
	this->window = window;
	this->camera_in_scene = new Camera();
	this->camera_in_scene->position.z = 50;
	object_in_scene.push_back(camera_in_scene);

	timer = new Timer();

	//�ּ��޾ƾߵ�
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
		//glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//for camera move.
		Input_check::input_check(object_in_scene);

		timer->tick();
		gamemanager->run();

		gamemanager->focused_block->update();
		gamemanager->focused_block->render(this->camera_in_scene);

		for (int it = 0; it < gamemanager->block_in_game.size(); it++)
		{
			gamemanager->block_in_game.at(it)->render(this->camera_in_scene);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

