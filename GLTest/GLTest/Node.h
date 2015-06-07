#pragma once
#include "MyUtil.h"

class Node
{
public:
	Node();
	~Node();

	virtual bool		Init();
	virtual void		Draw() = 0;
	virtual void		Update(float dTime) = 0;

	void				Render();
	void				OnTick(float dTime);
	void				AddChild(Node* sphere);

	Vec3				GetPosition() const {return m_Pos; }
	Vec3				GetAngle() const {return m_Angle;}
	Vec3				GetScale() const {return m_Scale;}
	void				SetPosition(const Vec3& pos){m_Pos = pos;}
	void				SetAngle(const Vec3& angle){m_Angle = angle;}
	void				SetScale(const Vec3& scale) {m_Scale = scale; }

private:
	Vec3				m_Pos;
	Vec3				m_Angle;
	Vec3				m_Scale;
	std::vector<Node*>	m_Children;
};

