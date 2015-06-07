#include "pch.h"
#include "Planet.h"

Planet::Planet(PlanetType type)
	:m_Type(type)
{

}


Planet::~Planet()
{
}

bool Planet::Init()
{
	if(!Sphere::Init())
	{
		return false;
	}

	size_t typeIdx = static_cast<size_t>( m_Type );
	PlanetInfo info = planetInfos[typeIdx];
	size_t textureIdx = static_cast<size_t>(info.m_TextureType);
	GLuint texId = textureInfo[textureIdx].id;

	SetTexture(texId);
	SetRadius(info.m_Radius);
	SetPosition(info.m_FirstPos);
}
