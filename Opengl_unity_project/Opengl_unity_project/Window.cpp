#include "Window.h"


Window::Window()
{
	if (this->init_glfw()) 
	{
		this->window = glfwCreateWindow(640, 480, "My title", NULL, NULL);
		glfwMakeContextCurrent(window);
	}
	init_glew();

	load_scene();
}


Window::~Window()
{
}


bool Window::init_glfw()
{
	if (!glfwInit())
	{
		std::fprintf(stderr, "Failed to initialize GLFW\n");
		return false;
	}
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	return true;
}

bool Window::init_glew()
{
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		std::cout << "???!";
		fprintf(stderr, "Failed to initialize GLEW\n");
		return false;
	}
	return true;
}

void Window::load_scene()
{
	current_scene = new Scene(window);
}

