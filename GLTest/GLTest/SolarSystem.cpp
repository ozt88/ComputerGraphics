#include "pch.h"
#include "Sun.h"
#include "Planet.h"
#include "SolarSystem.h"

unsigned width[TEXTURE_MAX], height[TEXTURE_MAX];
std::vector<unsigned char> image[TEXTURE_MAX];
GLuint texID[TEXTURE_MAX];


std::array< TextureInfo, TEXTURE_MAX > textureInfo =
{
	TextureInfo {0, "texture_sun.png"},
	TextureInfo {0, "texture_mercury.png"},
	TextureInfo {0, "texture_venus_atmosphere.png"},
	TextureInfo {0, "texture_earth_surface.png"},
	TextureInfo {0, "mars_texture.png"},
	TextureInfo {0, "texture_jupiter.png"},
	TextureInfo {0, "texture_saturn.png"},
	TextureInfo {0, "texture_uranus.png"},
	TextureInfo {0, "texture_neptune.png"},
};

std::array<PlanetInfo, PLANET_MAX> planetInfos =
{
	PlanetInfo {TextureType::MERCURY, 0.1f, Vec3(0.f, 0.f, 20.f)},
	PlanetInfo {TextureType::VENUS, 0.15f, Vec3(0.f, 0.f, 40.f)},
	PlanetInfo {TextureType::EARTH, 0.2f, Vec3(0.f, 0.f, 60.f)},
	PlanetInfo {TextureType::MARS, 0.2f, Vec3(0.f, 0.f, 80.f)},
	PlanetInfo {TextureType::JUPITER, 0.4f, Vec3(0.f, 0.f, 100.f)},
	PlanetInfo {TextureType::SATURN, 0.45f, Vec3(0.f, 0.f, 120.f)},
	PlanetInfo {TextureType::URANUS, 0.2f, Vec3(0.f, 0.f, 140.f)},
	PlanetInfo {TextureType::NEPTUNE, 0.2f, Vec3(0.f, 0.f, 160.f)},
};

SolarSystem::SolarSystem()
{
}


SolarSystem::~SolarSystem()
{
}

bool SolarSystem::Init()
{
	if(!Node::Init())
	{
		return false;
	}
	m_Sun = new Sun();
	m_Sun->Init();
	AddChild(m_Sun);
	

	Planet* planet = new Planet(PlanetType::EARTH);
	AddChild(planet);

	for(int i = 0; i < PLANET_MAX; ++i)
	{
		PlanetType type = static_cast<PlanetType>( i );
		Planet* planet = new Planet(type);
		m_Planets[i] = planet;
		AddChild(planet);
		planet->Init();
	}

	auto angle = GetAngle();
	angle.x += 10.f;
	SetAngle(angle);

	return true;
}

void SolarSystem::Draw()
{

}

void SolarSystem::Update(float dTime)
{
	Vec3 angle = GetAngle();
	angle.y += 0.2f * dTime;
	SetAngle(angle);
}

void SolarSystem::LoadTexture()
{
	unsigned error;

	for(int i = 0; i < TEXTURE_MAX; ++i)
	{
		error = lodepng::decode(image[i], width[i], height[i], textureInfo[i].path);

		if(error)
		{
			printf("error %u : %s\n", error, lodepng_error_text(error));
		}

		printf("\nimage size is %i", image[i].size());
	}

	glGenTextures(TEXTURE_MAX, texID);

	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	for(int i = 0; i < TEXTURE_MAX; ++i)
	{
		textureInfo[i].id = texID[i];
		glBindTexture(GL_TEXTURE_2D, texID[i]);
		gluBuild2DMipmaps(
			GL_TEXTURE_2D, 3, width[i], height[i],
			GL_RGBA, GL_UNSIGNED_BYTE, image[i].data()
			);
	}
}
