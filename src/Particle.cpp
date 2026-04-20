#include "Particle.hpp"
#include <cstdint>

Particle::Particle(const sf::Vector2f& position,
	const sf::Vector2f& velocity,
	float lifetime,
	const sf::Color& color, 
	float gravityStrength)
	: m_position(position),
	m_velocity(velocity),
	m_acceleration(0.f, gravityStrength),
	m_lifetime(lifetime),
	m_maxLifetime(lifetime),
	m_color(color)
{
}

void Particle::update(float dt)
{
	m_velocity += m_acceleration * dt;
	m_position += m_velocity * dt;

	m_lifetime -= dt;

	float lifeRatio = m_lifetime / m_maxLifetime;
	if (lifeRatio < 0.f)
		lifeRatio = 0.f;

	m_color.a = static_cast<std::uint8_t>(255.f * lifeRatio);
}

bool Particle::isAlive() const
{
	return m_lifetime > 0.f;
}

const sf::Vector2f& Particle::getPosition() const
{
	return m_position;
}

const sf::Color& Particle::getColor() const
{
	return m_color;
}