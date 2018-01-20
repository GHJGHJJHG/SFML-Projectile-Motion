/*
 * Arrow.hpp
 *
 *  Created on: Jan 2, 2018
 *      Author: Daniel Indictor
 */

#ifndef ARROW_HPP_
#define ARROW_HPP_

#include <SFML/Graphics.hpp>

#include <cmath>

void drawArrow(sf::RenderTarget& window, sf::Vector2f origin,
		double radians, double magnitude);

#endif /* ARROW_HPP_ */
