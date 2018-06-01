#include "Timer.h"

GLfloat Timer::deltatime;
GLuint Timer::fps;

Timer::Timer()
{
	Timer::deltatime = 0;
	Timer::fps = 0;
	old_time = 0;
}


Timer::~Timer()
{
}

void Timer::tick()
{
	GLfloat current_time = glfwGetTime();
	Timer::deltatime = current_time - old_time;
	old_time = current_time;
}

