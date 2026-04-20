#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "Particle.hpp"
#include <string>
#include <vector>

enum EmissionShape
{
	RADIAL,
	RING,
	CONE,
	DIRECTIONAL,
	EXPLOSIONWITHGRAVITY,
	NOGRAVITY,
};

class Emitter
{
public:
	Emitter(float minSpeed, float maxSpeed, int minLifetime, int maxLifetime,
		float gravityStrength, sf::Color baseColor, EmissionShape emissionShape, float particleSize);

	void emit(sf::Vector2f position, int count);
	void update(float dt);
	bool isEmpty() const;
	void draw(sf::RenderWindow& window);
private:
	float m_minSpeed;
	float m_maxSpeed;
	int m_minLifetime;
	int m_maxLifetime;
	float m_particleSize;
	float m_gravityStrength;
	sf::Color m_baseColor;
	EmissionShape m_emissionShape;
	float m_emissionRate;
	float m_timeAccumulator;
	std::vector<Particle> m_container;
};