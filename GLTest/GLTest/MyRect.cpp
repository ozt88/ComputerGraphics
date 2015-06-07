#include "pch.h"
#include "MyRect.h"

MyRect::MyRect()
	:m_Origin(), m_Size(), m_Velocity(), m_IsColliding(false)
{
}

MyRect::MyRect(Vec2 size, Vec2 pos, Vec2 vel, Vec3 color)
	: m_Origin(pos), m_Size(size), m_Velocity(vel), m_Color(color), m_IsColliding(false)
{
}


MyRect::~MyRect()
{
	for(auto child = m_Children.begin(); child != m_Children.end();)
	{
		auto delchild = child;
		delete *delchild;
		child = m_Children.erase(delchild);
	}
}

void MyRect::Draw()
{
	glColor3f(m_Color.x, m_Color.y, m_Color.z);
	glPushMatrix();
	glTranslatef(m_Origin.GetX(), m_Origin.GetY(), 0.f);
	glRectf(0, 0, m_Size.GetY(), m_Size.GetY());

	for(auto child : m_Children)
	{
		child->Draw();
	}
	glPopMatrix();
}

void MyRect::Update(int dTime)
{
	Move(dTime);

	for(auto child : m_Children)
	{
		child->Update(dTime);
	}

	BouncingWithParent();
	BouncingWithChildren();
}

void MyRect::AddChild(MyRect* child)
{
	m_Children.push_back(child);
	child->SetParent(this);
}

void MyRect::Move(float dTime)
{
	m_Origin._u += m_Velocity.GetX() * dTime / 100;
	m_Origin._v += m_Velocity.GetY() * dTime / 100;
}

bool MyRect::IsCollide(const MyRect& other)
{
	Vec2 myMin = m_Origin;
	Vec2 otherMin = other.GetOrigin();
	Vec2 myMax = myMin + m_Size;
	Vec2 otherMax = otherMin + other.GetSize();

	if(myMin.GetX() > otherMax.GetX() || myMax.GetX() < otherMin.GetX())
	{
		return false;
	}

	if(myMin.GetY() > otherMax.GetY() || myMax.GetY() < otherMin.GetY())
	{
		return false;
	}

	return true;
}

void MyRect::BouncingWithParent()
{
	if(m_Parent)
	{
		if(m_Origin.GetX() < 0 || m_Origin.GetX() + m_Size.GetX() > m_Parent->GetSize().GetX())
		{
			auto velX = m_Velocity.GetX();
			m_Velocity.SetX(-velX);
		}

		if(m_Origin.GetY() < 0 || m_Origin.GetY() + m_Size.GetY() >  m_Parent->GetSize().GetY())
		{
			auto velY = m_Velocity.GetY();
			m_Velocity.SetY(-velY);
		}
	}
}

void MyRect::BouncingWithChildren()
{
	for(int i = 0; i < m_Children.size(); i++)
	{
		for(int j = i + 1; j < m_Children.size(); j++)
		{
			MyRect* childA = m_Children[i];
			MyRect* childB = m_Children[j];

			if(childA->IsCollide(*childB))
			{
				Vec2 ChildAVelocity = childA->GetVelocity();
				Vec2 ChildBVelocity = childB->GetVelocity();
				childA->SetVelocity(ChildBVelocity);
				childB->SetVelocity(ChildAVelocity);
			}
		}
	}
}

void MyRect::MakeChildren()
{
	float width = m_Size.GetX();
	float height = m_Size.GetY();

	Vec2 size = Vec2(width*0.2f, height*0.2f);

	Vec2 pos1 = Vec2(width*0.2f, height*0.1f);
	Vec2 pos2 = Vec2(width*0.7f, height*0.7f);
	Vec2 pos3 = Vec2(width*0.7f, height*0.3f);

	Vec2 vel1;
	if(m_Velocity.GetX() == 0.f && m_Velocity.GetY() == 0.f)
	{
		vel1 = Vec2(30.f, 30.f);
	}
	else
	{
		vel1 = Vec2(m_Velocity.GetX()*0.2f, m_Velocity.GetY()*0.2f);
	}
	Vec2 vel2 = Vec2(vel1.GetX(), -vel1.GetY());
	Vec2 vel3 = Vec2(-vel1.GetX(), -vel1.GetY());



	Vec3 color1 = Vec3((float) ( rand() % 100 ) / 100, (float) ( rand() % 100 ) / 100, (float) ( rand() % 100 ) / 100);
	Vec3 color2 = Vec3((float) ( rand() % 100 ) / 100, (float) ( rand() % 100 ) / 100, (float) ( rand() % 100 ) / 100);
	Vec3 color3 = Vec3((float) ( rand() % 100 ) / 100, (float) ( rand() % 100 ) / 100, (float) ( rand() % 100 ) / 100);

	MyRect* rect1 = new MyRect(size, pos1, vel1, color1);
	MyRect* rect2 = new MyRect(size, pos2, vel2, color2);
	MyRect* rect3 = new MyRect(size, pos3, vel3, color3);

	AddChild(rect1);
	AddChild(rect2);
	AddChild(rect3);
}

