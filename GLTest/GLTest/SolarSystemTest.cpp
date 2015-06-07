#include "pch.h"
#include "SolarSystem.h"
#include "SolarSystemTest.h"

static float xRot = 0.f;
static float yRot = 0.f;
static GLfloat zDistance = 0.0f;
static SolarSystem solarSystem;
static GLfloat amb[] = {0.3f, 0.3f, 0.3f, 1.0f};
static GLfloat dif[] = {0.8f, 0.8f, 0.8f, 1.0f};
static GLfloat lightPos[] = {-50.f, 50.f, 100.f, 1.0f};

void SolarSystemTest::RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, zDistance);

	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);
	
	solarSystem.Render();

	glPopMatrix();
	glutSwapBuffers();
}

void SolarSystemTest::TimerFunc(int dTime)
{
	glutPostRedisplay();
	solarSystem.Update(dTime);

	glutTimerFunc(dTime, SolarSystemTest::TimerFunc, dTime);
}

void SolarSystemTest::SetUpRC()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.f, 0.f, 0.f, 1.f);
	solarSystem.LoadTexture();
	solarSystem.Init();
}

void SolarSystemTest::KeyControl(int key, int x, int y)
{
	if(key == GLUT_KEY_UP)
		xRot -= 5.0f;
	if(key == GLUT_KEY_DOWN)
		xRot += 5.0f;
	if(key == GLUT_KEY_LEFT)
		yRot -= 5.f;
	if(key == GLUT_KEY_RIGHT)
		yRot += 5.f;

	if(key == GLUT_KEY_F2)
		zDistance += 5.0f;
	if(key == GLUT_KEY_F3)
		zDistance -= 5.0f;

	glutPostRedisplay();
}

void SolarSystemTest::ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat fAspect;
	glViewport(0, 0, w, h);
	fAspect = (GLfloat) w / (GLfloat) h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.f, fAspect, 1.0f, 500.f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -50.f);
}

