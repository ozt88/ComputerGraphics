#include "pch.h"
#include "SpringTest.h"
#include "MyUtil.h"

static float xRot = 0.f;
static float yRot = 0.f;
static GLfloat zDistance = 0.0f;

void SpringTest::RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	glBegin(GL_LINE_STRIP);
	GLfloat x = 0.f;
	GLfloat y = 0.f;
	GLfloat z = -50.0f;
	GLfloat radius = 0.5f;

	for(GLfloat angle = 0.0f; angle <= ( 2.0f*PI )*10.0f; angle += 0.1f)
	{
		x = radius*sin(angle);
		y = radius*cos(angle);

		glColor3f(1.f, 1.f, 0.f);
		glVertex3f(x, y, z);

		z += 0.2f;
		radius += 0.1f;
	}
	glEnd();

	glPopMatrix();
	glutSwapBuffers();
}

void SpringTest::TimerFunc(int dTime)
{
	glutPostRedisplay();
	glutTimerFunc(30, TimerFunc, 0);
}

void SpringTest::SetUpRC()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void SpringTest::KeyControl(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
		xRot -= 5.0f;
		break;
		case GLUT_KEY_DOWN:
		xRot += 5.0f;
		break;
		case GLUT_KEY_LEFT:
		yRot -= 5.0f;
		break;
		case GLUT_KEY_RIGHT:
		yRot += 5.0f;
		break;
	}
}

void SpringTest::ChangeSize(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	GLfloat fAspect = (GLfloat) w / (GLfloat) h;
	GLfloat revfAspect = (GLfloat) h / (GLfloat) w;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(w <= h)
	{
		glOrtho(-100.f, 100.f, -100.f*revfAspect, 100.f*revfAspect, 100.f, -100.f);
	}
	else
	{
		glOrtho(-100 * fAspect, 100.f*fAspect, -100.f, 100.f, 100.f, -100.f);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}
