#pragma once
#include "Vertex.h"

class Mesh
{
public:
	Mesh();
	~Mesh();

	void Draw();
	
	std::vector<Vertex>		m_Vertices;
	std::vector<GLushort>	m_Indices;
};

