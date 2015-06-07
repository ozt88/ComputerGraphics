#include "pch.h"
#include "SolarSystemTest.h"
#include "RectangleCollisionTest.h"
#include "SpringTest.h"
#include "CubeTest.h"

enum TestType
{
	RECT_COLLISION,
	SPRING,
	CUBE,
	SOLAR_SYSTEM,
	TEST_MAX,
};

void NormalkeyInput(unsigned char key, int x, int y)
{
	if(key == 'q') exit(-1);
}


int main(void)
{
	srand(GetTickCount());
	

	unsigned int displayMode;
	std::string name;
	void(*renderScene)();
	void(*keyControl)( int, int, int );
	void(*changeSize)(int, int);
	void(*timerFunc)(int);
	void(*setUpRC)();

	//타입 번호를 바꿔서 테스트를 선택하세요
	TestType testType = (TestType)(rand() % 4);

	switch(testType)
	{
		//Rectangle Collision
		case RECT_COLLISION:
		{
			displayMode = RectangleCollisionTest::displayMode;
			name = RectangleCollisionTest::name;
			renderScene = RectangleCollisionTest::RenderScene;
			keyControl = RectangleCollisionTest::KeyControl;
			changeSize = RectangleCollisionTest::ChangeSize;
			timerFunc = RectangleCollisionTest::TimerFunc;
			setUpRC = RectangleCollisionTest::SetUpRC;
			break;
		}
		//Spring
		case SPRING:
		{
			displayMode = SpringTest::displayMode;
			name = SpringTest::name;
			renderScene = SpringTest::RenderScene;
			keyControl = SpringTest::KeyControl;
			changeSize = SpringTest::ChangeSize;
			timerFunc = SpringTest::TimerFunc;
			setUpRC = SpringTest::SetUpRC;
			break;
		}
		//Cube
		case CUBE:
		{
			displayMode = CubeTest::displayMode;
			name = CubeTest::name;
			renderScene = CubeTest::RenderScene;
			keyControl = CubeTest::KeyControl;
			changeSize = CubeTest::ChangeSize;
			timerFunc = CubeTest::TimerFunc;
			setUpRC = CubeTest::SetUpRC;
			break;
		}
		//Solar System
		case SOLAR_SYSTEM:
		{
			displayMode = SolarSystemTest::displayMode;
			name = SolarSystemTest::name;
			renderScene = SolarSystemTest::RenderScene;
			keyControl = SolarSystemTest::KeyControl;
			changeSize = SolarSystemTest::ChangeSize;
			timerFunc = SolarSystemTest::TimerFunc;
			setUpRC = SolarSystemTest::SetUpRC;
			break;
		}
	}


	glutInitDisplayMode(displayMode);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 800);
	glutCreateWindow(name.c_str());
	
	glutDisplayFunc(renderScene);
	glutSpecialFunc(keyControl);

	glutReshapeFunc(changeSize);
	glutKeyboardFunc(NormalkeyInput);
	glutTimerFunc(33, timerFunc,1);

	setUpRC();
	glutMainLoop();

	return true;
}
