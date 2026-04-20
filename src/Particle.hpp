#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Particle
{
public:
	Particle(const sf::Vector2f& position,
		const sf::Vector2f& velocity,
		float lifetime,
		const sf::Color& color, 
		float gravityStrength);

	void update(float dt);
	bool isAlive() const;

	const sf::Vector2f& getPosition() const;
	const sf::Color& getColor() const;

private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;

	float m_lifetime;
	float m_maxLifetime;
	sf::Color m_color;
};