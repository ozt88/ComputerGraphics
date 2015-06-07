#pragma once
#include "Geometry.h"

class Cube : public Geometry
{
public:
	Cube();
	~Cube();

	void LoadTexture(const char* path);
	void CreateMeshData() override;
	void SetSize(float size){SetScale(Vec3(size, size, size));};
private:
	GLuint m_TexId;
};

