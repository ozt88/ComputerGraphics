#pragma once
namespace CubeTest
{
	static unsigned int displayMode = GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH;
	static const char* name = "CubeTest";

	void RenderScene();
	void TimerFunc(int dTime);
	void SetUpRC();
	void KeyControl(int key, int x, int y);
	void ChangeSize(GLsizei w, GLsizei h);
}