#ifndef OCTREE_H
#define OCTREE_H

#include <vector>
#include <glm.hpp>
#include "Node.h"
#include "Particle.h"
#include "Physics.h"

class Node;
class Physics;

class Octree {
public:
    Octree(glm::dvec3 center, double radius, double theta, int maxDepth, int particlesSize);
    ~Octree();

    void buildTree(std::vector<Particle>* particles);
    double calculateTotalMassInSphere(glm::dvec3 targetPosition, double radius);
    double calculateTotalMassInSphere(Node* currentNode, glm::dvec3 targetPosition, double radius);
    void calcdensity(double h, double& medium, int& n);
    glm::dvec3 calculateForces(Physics* phy, Particle* particle, double softening, double a, double& potentialEngergy, double& calculations);
    void calcH(Particle* p);
private:

	Node* root;
    glm::dvec3 center;
    double radius;
    double theta;

    void insert(std::vector<Particle>* particles, int start, int end);
};

#endif // OCTREE_H