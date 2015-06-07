#include "pch.h"
#include "RectangleCollision.h"
#include "RectangleCollisionTest.h"

static RectangleCollision rectangleCollision;

void RectangleCollisionTest::RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	rectangleCollision.Draw();
	glutSwapBuffers();
}

void RectangleCollisionTest::TimerFunc(int dTime)
{
	glutPostRedisplay();
	rectangleCollision.Update(dTime);
	glutTimerFunc(dTime, RectangleCollisionTest::TimerFunc, dTime);
}

void RectangleCollisionTest::SetUpRC()
{
	glClearColor(0.f, 0.f, 1.0f, 1.0f);
	rectangleCollision.Init();
}

void RectangleCollisionTest::KeyControl(int key, int x, int y)
{

}

void RectangleCollisionTest::ChangeSize(GLsizei w, GLsizei h)
{

	glViewport(0, 0, w, h);
	GLfloat fAspect = (GLfloat) w / (GLfloat) h;
	GLfloat revfAspect = (GLfloat) h / (GLfloat) w;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	if(w <= h)
	{
		glOrtho(-100.f, 100.f, -100.f*revfAspect, 100.f*revfAspect, 1.f, -1.f);
	}
	else
	{
		glOrtho(-100 * fAspect, 100.f*fAspect, -100.f, 100.f, 1.f, -1.f);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


}



