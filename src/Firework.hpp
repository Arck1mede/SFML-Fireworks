#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Emitter.hpp"

class Firework
{
public:
	Firework(sf::Vector2f startPosition);

	void update(float dt);
	void draw(sf::RenderWindow& window);
	bool isFinished() const;

private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	float m_targetHeight;
	bool m_hasExploded;
	bool m_isFinished;
	Emitter m_trailEmitter;
	Emitter m_explosionEmitter;
};