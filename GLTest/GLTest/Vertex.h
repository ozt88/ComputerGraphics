#pragma once
#include "MyUtil.h"

class Vertex
{
public:
	Vertex();
	Vertex(Vec3 pos, Vec3 color, Vec3 normal, Vec2 texture);

	Vertex(
		float px, float py, float pz,
		float nx, float ny, float nz,
		float tx, float ty, float tz,
		float u, float v);

	~Vertex();

	void SetPos(const Vec3& pos) {m_Pos = pos;}
	void SetColor(const Vec3& color) {m_Color = color; }
	void SetNormal(const Vec3& normal) {m_Normal = normal;}
	void SetTangentU(const Vec3& tanU) {m_TangentU = tanU; }
	void SetTexture(const Vec2& tex) {m_Texture = tex;}

	Vec3 GetPos()const { return m_Pos; }
	Vec3 GetColor() const {return m_Color; }
	Vec3 GetNormal() const {return m_Normal;}
	Vec3 GetTangentU() const {return m_TangentU; }
	Vec2 GetTexture() const {return m_Texture; }

	void Draw();

private:
	Vec3	m_Color;
	Vec3	m_Pos;
	Vec3	m_Normal;
	Vec3	m_TangentU;
	Vec2	m_Texture;
};

