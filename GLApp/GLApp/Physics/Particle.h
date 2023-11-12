#pragma once
#include <glm.hpp>
#include "gtc/matrix_transform.hpp"

class Particle 
{
public:

    Particle(double x = 0.0f, double y = 0.0f, double z = 0.0f);


    //Physically variables
    glm::dvec3 position = { 0,0,0 };
    glm::dvec3 velocity = { 0,0,0 };
    double mass;

    //dark matter or not
    bool darkMatter = false;


    //variables for render
    double radius;
    glm::vec3 color;

    //Help functions
    double CalculateDistance(const Particle& other) const;

    //Physically functions
    glm::dvec3 calculateGravitationalForce(const Particle& other, double G, double softening, double deltaTime);
    glm::dvec3 calcAcceleration(glm::dvec3 force);

    //Diffrent numerical methods
    //semi-implicit Euler
    void eulerUpdateVelocity(glm::dvec3 acceleration, double deltaTime);
    void eulerUpdatePosition(glm::dvec3 velocity, double deltaTime);

    //Runge-Kutta order 4
    void rungeKuttaUpdateVelocity(glm::dvec3 acceleration, double deltaTime);
	void rungeKuttaUpdatePosition(glm::dvec3 velocity, double deltaTime);

    //leapfrog
    void leapfrogUpdateVelocity(glm::dvec3 acceleration, double deltaTime);
    void leapfrogUpdatePosition(glm::dvec3 velocity, double deltaTime);



    //Energie functions
    double calcKineticEnergie();
    double calcPotentialEnergie(const Particle& other, double G, double softening);

};