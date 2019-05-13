#include "Timer.h"
#include "Shader.h"

GLfloat Timer::deltatime;
GLuint Timer::fps;
GLfloat Timer::runningtime;

Timer::Timer()
{
	Timer::runningtime = 0;
	Timer::deltatime = 0;
	Timer::fps = 0;
	old_time = 0;
	time_started = glfwGetTime();
}


Timer::~Timer()
{
}

void Timer::tick()
{
	GLfloat current_time = glfwGetTime();
	Timer::deltatime = current_time - old_time;
	Timer::runningtime += deltatime;
	old_time = current_time;
	for (int i = 0; i < Shader::shaders.size(); i++) {
		glUseProgram(Shader::shaders.at(i));
		GLuint time = glGetUniformLocation(Shader::shaders.at(i), "time");

		glUniform1f(time, this->runningtime);
	}
}

