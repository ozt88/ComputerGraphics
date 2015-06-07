#pragma once
#include "Node.h"

class Planet;
class Sphere;

enum class TextureType
{
	SUN,
	MERCURY,
	VENUS,
	EARTH,
	MARS,
	JUPITER,
	SATURN,
	URANUS,
	NEPTUNE,
	TEXTURE_MAX,
};

const size_t TEXTURE_MAX = static_cast<size_t>(TextureType::TEXTURE_MAX);

struct TextureInfo
{
	GLuint id;
	const char* path;
};

enum class PlanetType
{
	MERCURY,
	VENUS,
	EARTH,
	MARS,
	JUPITER,
	SATURN,
	URANUS,
	NEPTUNE,
	PLANET_MAX,
};

const size_t PLANET_MAX = static_cast<size_t>( PlanetType::PLANET_MAX );

struct PlanetInfo
{
	TextureType m_TextureType;
	float m_Radius;
	Vec3 m_FirstPos;
};

extern std::array<TextureInfo, TEXTURE_MAX> textureInfo;
extern std::array<PlanetInfo, PLANET_MAX> planetInfos;

class SolarSystem : public Node
{
public:
	SolarSystem();
	~SolarSystem();

	bool		Init() override;
	void		Draw() override;
	void		Update(float dTime) override;
	void		LoadTexture();

private:
	Sphere*		m_Sun;
	std::array<Planet*, PLANET_MAX> m_Planets;
};

