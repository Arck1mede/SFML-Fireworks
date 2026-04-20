#include "Emitter.hpp"
#include "Random.hpp"
#include <algorithm>
#include <cmath>
#include <numbers>

Emitter::Emitter(float minSpeed, float maxSpeed, int minLifetime, int maxLifetime,
	float gravityStrength, sf::Color baseColor, EmissionShape emissionShape, float particleSize) :
	m_minSpeed(minSpeed),
	m_maxSpeed(maxSpeed),
	m_minLifetime(minLifetime),
	m_maxLifetime(maxLifetime),
	m_gravityStrength(gravityStrength),
	m_baseColor(baseColor),
	m_emissionShape(emissionShape),
	m_particleSize(particleSize)
{
};

void Emitter::emit(sf::Vector2f position, int count)
{
	for (int i = 0; i < count; i++)
	{
		float randSpeed = Random::getRandomFloat(m_minSpeed, m_maxSpeed);
		float randLifetime = Random::getRandomInt(m_minLifetime, m_maxLifetime);
		float randAngle = Random::getRandomAngle(0.0f, 2.0f * std::numbers::pi);;

		switch (m_emissionShape)
		{
		case RADIAL:
			break;
		case RING:
			randSpeed = m_minSpeed;
			break;
		case CONE:
		{
			float centerAngle = std::numbers::pi / 2.f; 
			float spread = std::numbers::pi / 10.f; 
			randAngle = Random::getRandomAngle(centerAngle - spread, centerAngle + spread);
			break;
		}
		case DIRECTIONAL:
		{
			float centerAngle = (3.f * std::numbers::pi) / 2.f; 
			float smallSpread = std::numbers::pi / 18.f; 
			randAngle = Random::getRandomAngle(centerAngle - smallSpread, centerAngle + smallSpread);
			break;
		}
		case EXPLOSIONWITHGRAVITY:
			break;
		case NOGRAVITY:
			break;
		}

		sf::Vector2f directionVec;
		directionVec.x = std::cos(randAngle);
		directionVec.y = std::sin(randAngle);

		sf::Vector2f velocity = directionVec * randSpeed;

		sf::Color randColor = Random::getRandomColor(0, 255);

		Particle particle = Particle(position, velocity, randLifetime, randColor, m_gravityStrength);
		m_container.push_back(particle);
	}
}

void Emitter::update(float dt)
{
	for (Particle& particle : m_container)
	{
		particle.update(dt);
	}
	m_container.erase(std::remove_if(m_container.begin(), m_container.end(), [](const Particle& p) { return !p.isAlive(); }), m_container.end());
}

bool Emitter::isEmpty() const
{
	return m_container.empty();
}

void Emitter::draw(sf::RenderWindow& window)
{
	for (const Particle& particle : m_container)
	{
		sf::CircleShape shape(m_particleSize);
		shape.setPosition(particle.getPosition());
		shape.setFillColor(particle.getColor());
		window.draw(shape);
	}
}