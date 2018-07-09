#include "Light.h"



Light::Light()
{
}


Light::~Light()
{
}

void Light::init_light()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);                 // 검은색으로 화면 지움
	glShadeModel(GL_SMOOTH);                              // 매끄러운 세이딩 사용
	glEnable(GL_DEPTH_TEST);                              // 가려진 면 제거
	glEnable(GL_CULL_FACE);                               // 후면 제거
	glFrontFace(GL_CW);                                  // 다각형을 반시계방향으로 감는다.

	glEnable(GL_LIGHTING);                                // 조명 활성화

														  // LIGHT0 에 대한 재질을 설정
	//glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);

	// LIGHT0 설정
	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);       // 주변광 성분 설정
	glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);       // 분산광 성분 설정
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);     // 광원 위치 설정
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

														  // LIGHT0을 켠다.
	glEnable(GL_LIGHT0);
}
