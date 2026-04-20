#include "Random.hpp"


std::mt19937 Random::engine(std::random_device{}());

float Random::getRandomFloat(float min, float max)
{
	std::uniform_real_distribution<float> distribution(min, max);
	return distribution(engine);
};

int Random::getRandomInt(int min, int max)
{
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(engine);
};

float Random::getRandomAngle(float min, float max)
{
	std::uniform_real_distribution<float> distribution(min, max);
	return distribution(engine);
}

sf::Color Random::getRandomColor(int min, int max)
{
	int r = Random::getRandomInt(min, max);
	int g = Random::getRandomInt(min, max);
	int b = Random::getRandomInt(min, max);

	return sf::Color(r, g, b);
}