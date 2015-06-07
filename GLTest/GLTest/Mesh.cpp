#include "pch.h"
#include "Mesh.h"


Mesh::Mesh()
{
}


Mesh::~Mesh()
{
}

void Mesh::Draw()
{
	for(int idx = 0; idx < m_Indices.size(); ++idx)
	{
		GLint index = m_Indices[idx];
		m_Vertices[index].Draw();
	}
}
