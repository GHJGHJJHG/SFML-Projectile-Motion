/*
 * Simulation.hpp
 *
 *  Created on: Dec 25, 2017
 *      Author: Daniel Indictor
 */

#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_

#include "config.hpp"
#include "utils.hpp"
#include "arrow.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#define SIMULATION_COLOR_SKYBLUE sf::Color(0x87ceeb)
#define SIMULATION_OUTLINE_WIDTH .03
#define SIMULATION_OUTLINE_COLOR sf::Color::Black

void setFrameRate(sf::RenderWindow& window, const int& frameRateLimit);

int playSimulation(const Config& config);

#endif /* SIMULATION_HPP_ */
