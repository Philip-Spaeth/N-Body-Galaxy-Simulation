#ifndef SYSTEMINIT_H
#define SYSTEMINIT_H

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Particle.h"
#include "Physics.h"
#include <glm.hpp>
#include "Galaxies/BarredGalaxy.h"
#include "Galaxies/SpiralGalaxy.h"
#include "Galaxies/EllipticalGalaxy.h"
#include "Halo.h"

class SystemInit 
{
public:
	void start(Physics* phy, std::vector<Particle>& particles);

private:
	Physics physics;

	BarredGalaxy barredGalaxy;
	SpiralGalaxy spiralGalaxy;
	EllipticalGalaxy ellipticalGalaxy;
	Halo halo;

	//solar system
	void solarSystem(std::vector<Particle>& particles);
	void ourSolarSystem(std::vector<Particle>& particles);
};

#endif