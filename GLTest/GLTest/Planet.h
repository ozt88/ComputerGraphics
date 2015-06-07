#pragma once
#include "Sphere.h"
#include "SolarSystem.h"

class Planet : public Sphere
{
public:
	Planet(PlanetType type);
	~Planet();
	bool Init() override;

private:
	PlanetType	m_Type;
};

