/*
 * utils.cpp
 *
 *  Created on: Dec 29, 2017
 *      Author: Daniel Indictor
 */

#ifndef UTILS_CPP_
#define UTILS_CPP_

#include "utils.hpp"

/**
 * Convenience function for setting the framerate of a window.
 *
 * \param window window to be modified.
 * \param frameRateLimit Framerate limit. Setting to CONFIG_FRAMRATE_DISABLED
 * disables any limits on framerates, and setting to CONFIG_FRAMERATE_VSYNC
 * enables V-Sync. Other values will be passed as the framerate limit.
 */
void setFrameRate(sf::RenderWindow& window, const int& frameRateLimit)
{
	switch(frameRateLimit)
	{
	case(CONFIG_FRAMERATE_DISABLED):
	{
		window.setVerticalSyncEnabled(false);
		std::cout << "Framerate: No limit" << std::endl;
		break;
	}
	case(CONFIG_FRAMERATE_VSYNC):
	{
		window.setVerticalSyncEnabled(true);
		std::cout << "Framerate: VSync enabled" << std::endl;
		break;
	}
	default:
	{
		window.setFramerateLimit(frameRateLimit);
		std::cout << "Framerate: " + std::to_string(frameRateLimit) << std::endl;
	}
	}
}

double sinDeg(const double& deg)
{
	return std::sin(deg * M_PIl/180);
}

double cosDeg(const double& deg)
{
	return std::cos(deg * M_PIl/180);
}

sf::Vector2f getProjectilePosition(const Config& config, const double& t)
{

	double vix = cosDeg(config.initialAngle()) * config.initialVelocity();
	double viy = sinDeg(config.initialAngle()) * config.initialVelocity();

	return sf::Vector2f(
			vix * t,
			(t * t * config.gravity()/2) + //t^2*g/2+viy*t+h
			(viy * t) + config.initialHeight());
}


#endif /* UTILS_CPP_ */
