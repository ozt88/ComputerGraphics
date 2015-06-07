#pragma once
#include "MyUtil.h"

enum class CollisionType
{
	NONE,
	HORIZONTAL,
	VERTICAL,
};

class MyRect
{
public:

	MyRect();
	MyRect(Vec2 size, Vec2 pos, Vec2 vel, Vec3 color);
	~MyRect();

	void	Draw();
	void	Update(int dTime);
	void	AddChild(MyRect* child);
	MyRect*	GetParent(){return m_Parent;}
	Vec2	GetOrigin() const {return m_Origin; }
	Vec2	GetSize() const {return m_Size; }
	Vec2	GetVelocity() const {return m_Velocity; }
	void	SetVelocity(Vec2 vel) { m_Velocity= vel;}
	void	MakeChildren();
	const std::vector<MyRect*>& GetChildren() const {return m_Children;}

private:

	void	SetParent(MyRect* parent) {m_Parent = parent; }
	bool	IsCollide(const MyRect& other);
	CollisionType CollisionCheck(const MyRect& other);
	void	BouncingWithChildren();
	void	BouncingWithParent();
	void	Move(float dTime);

private:
	bool	m_IsColliding;
	Vec2	m_Origin;
	Vec2	m_Size;
	Vec2	m_Velocity;
	Vec3	m_Color;
	MyRect*	m_Parent;
	std::vector<MyRect*> m_Children;
};

