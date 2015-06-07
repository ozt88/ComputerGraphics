#include "pch.h"
#include "SolarSystem.h"
#include "Sun.h"


Sun::Sun()
	:Sphere(1.f)
{
}


Sun::~Sun()
{
}

bool Sun::Init()
{
	if(!Sphere::Init())
	{
		return false;
	}
	size_t infoIdx = static_cast<size_t>( TextureType::SUN );
	SetTexture(textureInfo[infoIdx].id);
}
