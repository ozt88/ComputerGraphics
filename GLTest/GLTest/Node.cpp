#include "pch.h"
#include "Node.h"

Node::Node()
	:m_Pos(0.f, 0.f, 0.f), m_Angle(0.f, 0.f, 0.f), m_Scale(1.f, 1.f, 1.f)
{
}

Node::~Node()
{
}

void Node::Render()
{

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

 	glRotatef(m_Angle.x, 1.0f, 0.0f, 0.0f);
	glRotatef(m_Angle.y, 0.0f, 1.0f, 0.0f);
	glRotatef(m_Angle.z, 0.0f, 0.0f, 1.0f);
	glScalef(m_Scale.x, m_Scale.y, m_Scale.z);
	glTranslatef(m_Pos.x, m_Pos.y, m_Pos.z);
	
	Draw();

	for(auto child : m_Children)
	{
		child->Render();
	}
	glPopMatrix();
}

bool Node::Init()
{
	return true;
}


void Node::OnTick(float dTime)
{
	Update(dTime);
	for(auto child : m_Children)
	{
		child->OnTick(dTime);
	}
}

void Node::AddChild(Node* sphere)
{
	m_Children.push_back(sphere);
}
