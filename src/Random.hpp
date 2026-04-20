#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include <numbers>
#include <random>

class Random
{
public:
	static float getRandomFloat(float min, float max);
	static int getRandomInt(int min, int max);
	static float getRandomAngle(float min = 0.f, float max = std::numbers::pi * 2.f);
	static sf::Color getRandomColor(int min = 0, int max = 255);

private:
	static std::mt19937 engine;
};
