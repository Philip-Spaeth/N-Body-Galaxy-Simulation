#pragma once

#include <glm.hpp>
#include "Particle.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include "Physics.h"

class Physics;


class FileManager
{
	public:
	FileManager(std::string dataFolder);
	~FileManager();

	std::string dataFolder = "Data";
	std::unordered_map<std::string, std::string> readConfig(const std::string& filename);
	glm::vec3 parseVector3(const std::string& vecString);
	std::unordered_map<std::string, std::string> readTheConfig(const std::string& filename);

	void saveParticles(int timestep, const std::vector<Particle>& particles, const std::string& path);
	void loadParticles(Physics* p, int timestep, std::vector<glm::vec4>& array, std::vector<glm::vec3>& color, std::vector<glm::vec3>& densitycolor, std::vector<glm::vec3>& thermalColor, std::vector<glm::vec1>& isDarkMatter, int maxNumberOfParticles);

	void saveEnergieData(std::vector<std::vector<double>>& totalEnergie, std::string path);

	//rotationCurve in galaxy, dark and visible matter
	void saveRotationCurve(std::vector<Particle>& particles, std::string path);

	//massCurve in galaxy, dark and visible matter
	void saveMassCurve(std::vector<Particle>& particles, std::string path);
};