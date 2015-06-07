#include "pch.h"
#include "Vertex.h"


Vertex::Vertex()
{
}

Vertex::Vertex(Vec3 pos, Vec3 color, Vec3 normal, Vec2 texture)
	:m_Color(color), m_Pos(pos), m_Normal(normal), m_Texture(texture)
{
}

Vertex::Vertex(float px, float py, float pz, float nx, float ny, float nz, float tx, float ty, float tz, float u, float v)
	: m_Pos(px, py, pz), m_Normal(nx, ny, nz), m_TangentU(tx, ty, tz), m_Texture(u, v)
{
}


Vertex::~Vertex()
{
}

void Vertex::Draw()
{
	glColor3f(m_Color.x, m_Color.y, m_Color.z);
	glNormal3f(m_Normal.x, m_Normal.y, m_Normal.z);
	glTexCoord2f(m_Texture._u, m_Texture._v);
	glVertex3f(m_Pos.x, m_Pos.y, m_Pos.z);

}
