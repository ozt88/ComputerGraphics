#pragma once
#include "Geometry.h"
class Sphere : public Geometry
{
public:
	Sphere();
	Sphere(float radius);
	~Sphere();

	void CreateMeshData() override;
	void Subdivide(Mesh& mesh);
	void SetRadius(float radius) {SetScale(Vec3(radius, radius, radius)); }
	//void Draw() override;
private:
	float m_Radius;
};

