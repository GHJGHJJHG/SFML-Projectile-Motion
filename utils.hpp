/*
 * utils.hpp
 *
 *  Created on: Dec 29, 2017
 *      Author: Daniel Indictor
 */

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include "config.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>

#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <cmath>

void setFrameRate(sf::RenderWindow& window, const int& frameRateLimit);

double sinDeg(const double& deg);
double cosDeg(const double& deg);

sf::Vector2f getProjectilePosition(const Config& config, const double& time);

#endif /* UTILS_HPP_ */
