#include "pch.h"
#include "Sphere.h"
#include "MathHelper.h"

Sphere::Sphere()
	:m_Radius(1.f)
{
}

Sphere::Sphere(float radius)
	: m_Radius(radius)
{
}


Sphere::~Sphere()
{
}

void Sphere::CreateMeshData()
{
	int numSubdivisions = 3;

	// Approximate a sphere by tessellating an icosahedron.

	const float X = 0.525731f;
	const float Z = 0.850651f;

	Vec3 pos[12] =
	{
		Vec3(-X, 0.0f, Z),
		Vec3(X, 0.0f, Z),
		Vec3(-X, 0.0f, -Z),
		Vec3(X, 0.0f, -Z),
		Vec3(0.0f, Z, X),
		Vec3(0.0f, Z, -X),
		Vec3(0.0f, -Z, X),
		Vec3(0.0f, -Z, -X),
		Vec3(Z, X, 0.0f),
		Vec3(-Z, X, 0.0f),
		Vec3(Z, -X, 0.0f),
		Vec3(-Z, -X, 0.0f)
	};

	DWORD k[60] =
	{
		1, 4, 0, 4, 9, 0, 4, 5, 9, 8, 5, 4, 1, 8, 4,
		1, 10, 8, 10, 3, 8, 8, 3, 5, 3, 2, 5, 3, 7, 2,
		3, 10, 7, 10, 6, 7, 6, 11, 7, 6, 0, 11, 6, 1, 0,
		10, 1, 6, 11, 0, 9, 2, 11, 9, 5, 2, 9, 11, 2, 7
	};

	m_Mesh.m_Vertices.resize(12);
	m_Mesh.m_Indices.resize(60);

	for(UINT i = 0; i < 12; ++i)
		m_Mesh.m_Vertices[i].SetPos(pos[i]);

	for(UINT i = 0; i < 60; ++i)
		m_Mesh.m_Indices[i] = k[i];

	for(UINT i = 0; i < numSubdivisions; ++i)
		Subdivide(m_Mesh);

	// Project vertices onto sphere and scale.
	for(UINT i = 0; i < m_Mesh.m_Vertices.size(); ++i)
	{
		// Project onto unit sphere.
		auto pos = m_Mesh.m_Vertices[i].GetPos();
		Vec3 n = pos.Normalize();

		// Project onto sphere.
		Vec3 p = n * m_Radius;

		m_Mesh.m_Vertices[i].SetPos(p);
		m_Mesh.m_Vertices[i].SetNormal(n);

		// Derive texture coordinates from spherical coordinates.
		MathHelper mathHelper;
		float theta = mathHelper.AngleFromXY(m_Mesh.m_Vertices[i].GetPos().x,
								  m_Mesh.m_Vertices[i].GetPos().z);

		float phi = acosf(m_Mesh.m_Vertices[i].GetPos().y / m_Radius);

		m_Mesh.m_Vertices[i].SetTexture(Vec2(theta / (PI * 2), phi / PI));

		// Partial derivative of P with respect to theta
		m_Mesh.m_Vertices[i].SetTangentU
			(Vec3(
			-m_Radius*sinf(phi)*sinf(theta),
			0.0f,m_Radius*sinf(phi)*cosf(theta)));

		m_Mesh.m_Vertices[i].SetTangentU(m_Mesh.m_Vertices[i].GetTangentU().Normalize());
	}
}

void Sphere::Subdivide(Mesh& mesh)
{
	// Save a copy of the input geometry.
	Mesh inputCopy = mesh;


	mesh.m_Vertices.resize(0);
	mesh.m_Indices.resize(0);

	//       v1
	//       *
	//      / \
			//     /   \
			//  m0*-----*m1
	//   / \   / \
			//  /   \ /   \
			// *-----*-----*
	// v0    m2     v2

	UINT numTris = inputCopy.m_Indices.size() / 3;
	for(UINT i = 0; i < numTris; ++i)
	{
		Vertex v0 = inputCopy.m_Vertices[inputCopy.m_Indices[i * 3 + 0]];
		Vertex v1 = inputCopy.m_Vertices[inputCopy.m_Indices[i * 3 + 1]];
		Vertex v2 = inputCopy.m_Vertices[inputCopy.m_Indices[i * 3 + 2]];

		//
		// Generate the midpoints.
		//

		Vertex m0, m1, m2;

		// For subdivision, we just care about the position component.  We derive the other
		// vertex components in CreateGeosphere.

		m0.SetPos(Vec3(
			0.5f*( v0.GetPos().x + v1.GetPos().x ),
			0.5f*( v0.GetPos().y + v1.GetPos().y ),
			0.5f*( v0.GetPos().z + v1.GetPos().z )));

		m1.SetPos(Vec3(
			0.5f*( v1.GetPos().x + v2.GetPos().x ),
			0.5f*( v1.GetPos().y + v2.GetPos().y ),
			0.5f*( v1.GetPos().z + v2.GetPos().z )));

		m2.SetPos(Vec3(
			0.5f*( v0.GetPos().x + v2.GetPos().x ),
			0.5f*( v0.GetPos().y + v2.GetPos().y ),
			0.5f*( v0.GetPos().z + v2.GetPos().z )));

		//
		// Add new geometry.
		//

		m_Mesh.m_Vertices.push_back(v0); // 0
		m_Mesh.m_Vertices.push_back(v1); // 1
		m_Mesh.m_Vertices.push_back(v2); // 2
		m_Mesh.m_Vertices.push_back(m0); // 3
		m_Mesh.m_Vertices.push_back(m1); // 4
		m_Mesh.m_Vertices.push_back(m2); // 5

		m_Mesh.m_Indices.push_back(i * 6 + 0);
		m_Mesh.m_Indices.push_back(i * 6 + 3);
		m_Mesh.m_Indices.push_back(i * 6 + 5);

		m_Mesh.m_Indices.push_back(i * 6 + 3);
		m_Mesh.m_Indices.push_back(i * 6 + 4);
		m_Mesh.m_Indices.push_back(i * 6 + 5);

		m_Mesh.m_Indices.push_back(i * 6 + 5);
		m_Mesh.m_Indices.push_back(i * 6 + 4);
		m_Mesh.m_Indices.push_back(i * 6 + 2);

		m_Mesh.m_Indices.push_back(i * 6 + 3);
		m_Mesh.m_Indices.push_back(i * 6 + 1);
		m_Mesh.m_Indices.push_back(i * 6 + 4);
	}
}

// void Sphere::Draw()
// {
// 	glBindTexture(GL_TEXTURE_2D, m_TextureId);
// 	glutSolidSphere(m_Radius, 50, 50);
// }