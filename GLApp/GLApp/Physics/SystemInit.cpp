#include "SystemInit.h"
#include <iostream>
#include <cmath>


void SystemInit::start(std::vector<std::vector<Particle>>& particles)
{

	solarSystem(particles);

	//galaxy(0, { 0,0,0 }, { 0,0,0 }, particles);
	//galaxy(1000, { 5000000, 3000,0 }, { 0,0,0 }, particles);
}

void SystemInit::galaxy(int size, glm::vec3 position, glm::vec3 velocity, std::vector<std::vector<Particle>>& particles)
{
	// Change: Set values for diskRadius and starSpeed to good defaults
	double diskRadius = 200;
	double starSpeed = 0.03;

	//Creating a galaxy like the milky way
	for (int j = size; j < physics.particlesSize; j++)
	{
		//black hole in the middle
		if (j == size)
		{
			particles[0][j].position = position;
			particles[0][j].velocity = velocity;
			particles[0][j].mass = 1e12;
			particles[0][j].radius = 2;
			particles[0][j].color = glm::vec3(1, 1, 0);
		}

		//stars on a disk around the black hole with velocity so the stars stay on the orbit arod the vlack hole
		else
		{
			Particle particle;
			double r = physics.random(0.0, diskRadius);
			double angle = physics.random(0, 2 * 3.14);
			double v = std::sqrt((physics.G * particles[0][size].mass) / r) * starSpeed;
			particle.position = glm::vec3(r * std::cos(angle), r * std::sin(angle), 0) + particles[0][size].position + position;
			particle.velocity = glm::vec3(-v * std::sin(angle), v * std::cos(angle), 0) + particles[0][size].velocity + velocity;
			particle.mass = 0.5;
			particle.radius = 0.5;
			particle.color = glm::vec3(1, 1, 1);
			particles[0][j] = particle;
		}
	}
}


void SystemInit::solarSystem(std::vector<std::vector<Particle>>& particles)
{

	//works the best with 10 particles
	Physics physics;

	double distanceFaktor = 30;
	double velocityFaktor = 0.05;
	double antivelocityFaktor = 0.05;

	for (int j = 0; j < physics.particlesSize; j++)
	{
		//One sun with a lot of mass
		if (j == 0)
		{
			Particle particle;
			particle.position = glm::vec3(0, 0, 0);
			particle.velocity = glm::vec3(0, 0, 0);
			particle.mass = 1e14;
			particle.radius = 4;
			particle.color = glm::vec3(1, 1, 0);
			particles[0][j] = particle;
		}
		else
		{
			Particle particle;
			particle.position = glm::vec3(j * distanceFaktor, 0,0);
			double v;
			if (j > 1)
			{
				v = std::sqrt((physics.G * particles[0][0].mass) / (j)) * velocityFaktor;
			}
			else
			{
				v = std::sqrt((physics.G * particles[0][0].mass) / (j)) * antivelocityFaktor;
			}

			particle.velocity = glm::vec3(0, v, 0);
			particle.mass = 1;
			//diffrent color for every planet
			int color = j % 3;
			if (color == 0)
			{
				particle.color = glm::vec3(1, 0, 0);
			}
			else if (color == 1)
			{
				particle.color = glm::vec3(0, 1, 0);
			}
			else if (color == 2)
			{
				particle.color = glm::vec3(0, 0, 1);
			}

			//diffrent size for every planet
			int size = j % 3;
			if (size == 0)
			{
				particle.radius = 0.5;
			}
			else if (size == 1)
			{
				particle.radius = 1;
			}
			else if (size == 2)
			{
				particle.radius = 2;
			}
			particles[0][j] = particle;
		}
	}
}