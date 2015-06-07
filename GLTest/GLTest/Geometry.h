#pragma once
#include "Node.h"
#include "Mesh.h"

class Geometry : public Node
{
public:
	Geometry();
	~Geometry();
	
	bool Init()	override;
	void Draw() override;
	void Update(float dTime) override;
	bool SetTexture(int id);

protected:
	virtual void CreateMeshData();

protected:
	Mesh	m_Mesh;
	GLuint	m_TextureId;
};

