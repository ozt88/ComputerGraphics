#include "pch.h"
#include "RectangleCollision.h"


RectangleCollision::RectangleCollision()
	:MyRect(Vec2(100.f, 100.f), Vec2(-50.f,-50.f), Vec2(0.f, 0.f), Vec3(1.f, 1.f, 1.f))
{
}


RectangleCollision::~RectangleCollision()
{
}

bool RectangleCollision::Init()
{
	MakeChildren();

	for(auto child : GetChildren())
	{
		child->MakeChildren();
	}
	return true;
}
