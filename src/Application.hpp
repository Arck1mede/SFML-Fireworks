#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "Firework.hpp"

class Application
{
public:
	Application();
	void run();

private:
	void processEvents();
	void update(float dt);
	void render();

private:
	sf::RenderWindow m_window;
	sf::Clock m_clock;
	std::vector<Firework> m_fireworks;
};