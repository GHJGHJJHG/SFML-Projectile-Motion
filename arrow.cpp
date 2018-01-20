/*
 * Arrow.cpp
 *
 *  Created on: Jan 2, 2018
 *      Author: Daniel Indictor
 */

#include "arrow.hpp"

void drawArrow(sf::RenderTarget& window, sf::Vector2f origin,
		double radians, double magnitude)
{
	double normalizedRadians = atan2( -sin(radians), cos(radians));

	sf::ConvexShape arrow(4);
	arrow.setFillColor(sf::Color::Green);
	arrow.setOutlineColor(sf::Color::Black);
	arrow.setOutlineThickness(.01);

	arrow.setPoint(0, origin);
	arrow.setPoint(2,
			origin + sf::Vector2f(magnitude * cos(normalizedRadians),
			                      magnitude * sin(normalizedRadians)));
	arrow.setPoint(1,
			origin + sf::Vector2f(magnitude * .7 * cos(normalizedRadians + .1),
			                      magnitude * .7 * sin(normalizedRadians + .1)));
	arrow.setPoint(3,
			origin + sf::Vector2f(magnitude * .7 * cos(normalizedRadians - .1),
			                      magnitude * .7 * sin(normalizedRadians - .1)));

	window.draw(arrow);
}
