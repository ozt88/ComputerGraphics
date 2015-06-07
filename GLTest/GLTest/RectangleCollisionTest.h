#pragma once

namespace RectangleCollisionTest
{
	static const char* name = "RectangleCollisionTest";
	static unsigned int displayMode = GLUT_DOUBLE | GLUT_RGB;

	void RenderScene();
	void TimerFunc(int dTime);
	void SetUpRC();
	void KeyControl(int key, int x, int y);
	void ChangeSize(GLsizei w, GLsizei h);
}