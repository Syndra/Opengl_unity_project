#include "myGamemanager.h"
#include "Window.h"
#include "Scene.h"
#include "Camera.h"
#include "MyObject.h"
#include "FloorObject.h"
#include "MyLightSource.h"
#include "Transform.h"
#include "CameraTransform.h"
#include "Shader.h"
#include "LightTransform.h"
#include "MyTerrain.h"
#include "CameraUpdatable.h"
#include "SkyBox.h"
#include "Terrain.h"

myGamemanager::myGamemanager()
{
	Scene::camera_in_scene->transform->position = glm::vec3(0, 0, 1);
	Scene::camera_in_scene->transform->lookat = glm::vec3(0, 0, 0);
	//Scene::camera_in_scene->updatable->speed *= 10;
	//Scene::camera_in_scene->far *= 10;
	SkyBox *b = new SkyBox();
	

	MyTerrain *a1 = new MyTerrain();
	a1->transform->position.y = -146;
	a1->terrain->set_Transparency(1);
	a1->terrain->set_Color(glm::vec3(1, 1, 1));
	a1->terrain = new Terrain(7, 40, 0.008);
	a1->renderer->set_model(a1->terrain);
	a1->renderer->shader = Shader::BasicLightShader;

	MyTerrain *a = new MyTerrain();
	
	MyObject *c = new MyObject();

	//c->model->set_DrawType(GL_LINES);

	/*MyObject *wall = new MyObject();
	wall->transform->positio n = glm::vec3(0, 0, -10);
	wall->transform->scale = 20;
	wall->set_model("obj/plane_v.obj");
	wall->renderer->shader = Shader::panel;*/
	//c->model->set_DrawType(GL_LINES);
	//MyObject *c1 = new MyObject();
	//c1->set_model("obj/panel_v.obj");
	//c1->transform->position = glm::vec3(0, 0, 10);
	//c1->renderer->set_shader(Shader::AlphaTest);
	//MyObject *c2 = new MyObject();
	//c2->set_model("obj/panel_v.obj");
	//c2->transform->position = glm::vec3(0, 0, -10);
	//c2->renderer->set_shader(Shader::AlphaTest);
	//c->transform->scale = 10;


	spotlight = new MyLightSource();
	spotlight->transform->position = glm::vec3(0, 10, 0);
	spotlight->light->properties->lightColor = glm::vec3(1, 1, 1);
	spotlight->light->transform->euler_angle = glm::vec3(92, 0, 0);
	spotlight->light->transform->position = glm::vec3(0, 10, 0);
	spotlight->light->properties->Power = 0.1;
	spotlight->light->properties->type = 1;
	spotlight->light->properties->FOV = 0.2f;

	spotlight->renderer->set_RenderTarget(false);
	spotlight->renderer->set_ShadowTarget(false);


	MyLightSource *spotlight2 = new MyLightSource();
	spotlight2->transform->position = glm::vec3(0, 10, 0);
	spotlight2->light->properties->lightColor = glm::vec3(1, 1, 1);
	spotlight2->light->transform->euler_angle = glm::vec3(0.5f, 2.f, 2.0f);
	//spotlight2->light->transform->position = glm::vec3(10, 10, 0);
	spotlight2->light->properties->Power = 0.05;
	spotlight2->light->properties->type = 0;
	spotlight2->light->properties->FOV = 0.2f;

	spotlight2->renderer->set_RenderTarget(false);
	spotlight2->renderer->set_ShadowTarget(false);


	/*pointedlight = new MyLightSource();
	pointedlight->transform->position = glm::vec3(2, 2, 0);
	pointedlight->light->lightColor = glm::vec3(1,1,1);
	pointedlight->light->Power = 1;
	pointedlight->light->type = 1;*/
}


myGamemanager::~myGamemanager()
{
}

void myGamemanager::run()
{
	if (glfwGetKey(Window::window, GLFW_KEY_A) == GLFW_PRESS) {
		spotlight->transform->euler_angle.x -= 0.01;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_D) == GLFW_PRESS) {
		spotlight->transform->euler_angle.x += 0.01;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_S) == GLFW_PRESS) {
		spotlight->transform->position.y -= 0.1;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_W) == GLFW_PRESS) {
		spotlight->transform->position.y += 0.1;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_R) == GLFW_PRESS) {
		spotlight->transform->position.z -= 0.1;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_F) == GLFW_PRESS) {
		spotlight->transform->position.z += 0.1;
	}
}
