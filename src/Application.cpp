#include "Application.hpp"
#include <algorithm>

Application::Application() :
	m_window(sf::VideoMode({800u, 600u}), "Fireworks")
{
	m_window.setFramerateLimit(60);
}

void Application::run()
{
	while (m_window.isOpen())
	{
		float dt = m_clock.restart().asSeconds();
		processEvents();
		update(dt);
		render();
	}
}

void Application::processEvents()
{
	while (auto event = m_window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			m_window.close();
		}

		if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>())
		{
			if (mousePressed->button == sf::Mouse::Button::Left)
			{
				sf::Vector2f mousePos = m_window.mapPixelToCoords(mousePressed->position);
				m_fireworks.emplace_back(mousePos);
			}
		}
	}
}

void Application::update(float dt)
{
	for (auto& firework : m_fireworks)
	{
		firework.update(dt);
	}
	m_fireworks.erase(std::remove_if(
		m_fireworks.begin(),
		m_fireworks.end(),
		[](const Firework& fw)
		{
			return fw.isFinished();
		}),
		m_fireworks.end());
}

void Application::render()
{
	m_window.clear(sf::Color::Black);

	for (auto& firework : m_fireworks)
	{
		firework.draw(m_window);
	}
	m_window.display();
}