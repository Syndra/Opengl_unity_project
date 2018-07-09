#include "Light.h"



Light::Light()
{
}


Light::~Light()
{
}

void Light::init_light()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);                 // ���������� ȭ�� ����
	glShadeModel(GL_SMOOTH);                              // �Ų����� ���̵� ���
	glEnable(GL_DEPTH_TEST);                              // ������ �� ����
	glEnable(GL_CULL_FACE);                               // �ĸ� ����
	glFrontFace(GL_CW);                                  // �ٰ����� �ݽð�������� ���´�.

	glEnable(GL_LIGHTING);                                // ���� Ȱ��ȭ

														  // LIGHT0 �� ���� ������ ����
	//glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);

	// LIGHT0 ����
	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);       // �ֺ��� ���� ����
	glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);       // �л걤 ���� ����
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);     // ���� ��ġ ����
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

														  // LIGHT0�� �Ҵ�.
	glEnable(GL_LIGHT0);
}
