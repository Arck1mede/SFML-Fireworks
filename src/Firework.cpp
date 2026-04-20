#include "Firework.hpp"
#include "Random.hpp"
#include <iostream>

Firework::Firework(sf::Vector2f startPosition) :
	m_position(startPosition),
	m_velocity(0.f, -300.f),
	m_targetHeight(Random::getRandomFloat(150.f, 300.f)),
	m_hasExploded(false),
	m_isFinished(false),
	m_trailEmitter(150.f, 250.f, 0.6f, 1.2f, 0.f, sf::Color::Yellow, CONE, 1.f),
	m_explosionEmitter(100.f, 300.f, 1.f, 3.f, 200.f, sf::Color::White, RADIAL, 3.f)
{ }

void Firework::update(float dt)
{
	if (!m_hasExploded)
	{
		m_position += m_velocity * dt;

		m_trailEmitter.emit(m_position, 25);
		m_trailEmitter.update(dt);

		if (m_position.y <= m_targetHeight)
		{
			m_hasExploded = true;
			m_explosionEmitter.emit(m_position, 150);
		}
	}
	else
	{
		m_explosionEmitter.update(dt);
		m_trailEmitter.update(dt);

		if (m_trailEmitter.isEmpty() && m_explosionEmitter.isEmpty())
		{
			m_isFinished = true;
		}
	}
}

void Firework::draw(sf::RenderWindow& window)
{
	if (!m_hasExploded)
	{
		sf::CircleShape rocket(3.f);
		rocket.setFillColor(sf::Color::White);
		rocket.setPosition(m_position);
		window.draw(rocket);
	}
	
    m_trailEmitter.draw(window);

	if (m_hasExploded)
		m_explosionEmitter.draw(window);
}

bool Firework::isFinished() const
{
	return m_isFinished;
}