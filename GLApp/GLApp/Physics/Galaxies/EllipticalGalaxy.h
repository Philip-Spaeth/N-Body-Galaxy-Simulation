#ifndef ELLIPTICALGALAXY_H
#define ELLIPTICALGALAXY_H

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Particle.h"
#include "Physics.h"
#include <glm.hpp>

class EllipticalGalaxy
{
public:
	void S0(Physics* phy, int startIndex, int endIndex, glm::dvec3 position, glm::dvec3 rotation, glm::dvec3 velocity, double maxRadius, double Masse, double anteilBaryonischeMaterie, double anteilDunkleMaterie, double powNumberNormal, double powNumberDark, std::vector<Particle>& particles);
	void E0(int startIndex, int endIndex, glm::dvec3 position, glm::dvec3 rotation, glm::dvec3 velocity, double maxRadius, double Masse, double anteilBaryonischeMaterie, double anteilDunkleMaterie, double powNumberNormal, double powNumberDark, std::vector<Particle>& particles);
};

#endif