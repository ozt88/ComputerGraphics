#include "pch.h"
#include "Geometry.h"

Geometry::Geometry()
	:m_TextureId(0)
{
}


Geometry::~Geometry()
{
}

bool Geometry::Init()
{
	if(!Node::Init())
	{
		return false;
	}
	CreateMeshData();
	return true;
}

void Geometry::Draw()
{
	if(m_TextureId != 0)
	{
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glBindTexture(GL_TEXTURE_2D, m_TextureId);
	}
	glBegin(GL_TRIANGLES);
	m_Mesh.Draw();
	glEnd();
}

void Geometry::Update(float dTime)
{

}

void Geometry::CreateMeshData()
{

}

bool Geometry::SetTexture(int id)
{
	m_TextureId = id;
	return true;
}

