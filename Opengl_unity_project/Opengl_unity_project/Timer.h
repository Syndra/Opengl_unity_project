#pragma once
#include <gl\glew.h>
#include <GLFW\glfw3.h>
class Timer
{
public:

	static GLfloat deltatime;
	static GLuint fps;
	static GLfloat runningtime;

	GLfloat old_time;

	GLfloat time_started;

	Timer();
	~Timer();

	void tick();
};

