#pragma once
#include "Sphere.h"
class Sun : public Sphere
{
public:
	Sun();
	~Sun();
	bool Init() override;
};

