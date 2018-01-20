/*
 * Simulation.cpp
 *
 *  Created on: Dec 25, 2017
 *      Author: Daniel Indictor
 */

#include "simulation.hpp"

int playSimulation(const Config& config)
{

	//Localize some stuff. All units are MKS units (meters, kilograms, seconds)

	const float viewWidth = config.viewWidth();
	const float viewHeight = config.viewHeight();

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(
			config.windowWidth(),
			config.windowHeight()),
			config.windowName(),
			sf::Style::Default,
			settings);

	setFrameRate(window, config.frameRateLimit());
//	window.setFramerateLimit(2);

	//Set view to size.
	window.setView(sf::View(sf::FloatRect(0, 0, viewWidth, viewHeight)));

	sf::CircleShape circle(.1, 64);
	circle.setFillColor(sf::Color::Red);
	circle.setOutlineColor(SIMULATION_OUTLINE_COLOR);
	circle.setOutlineThickness(SIMULATION_OUTLINE_WIDTH);

	sf::RectangleShape ground(sf::Vector2f(viewWidth, config.floor()));
	ground.setFillColor(sf::Color(210, 105, 30));
	ground.setPosition(0, viewHeight - config.floor());

	sf::ConvexShape platform(4);
	platform.setFillColor(sf::Color::Red);
	platform.setOutlineColor(SIMULATION_OUTLINE_COLOR);
	platform.setOutlineThickness(SIMULATION_OUTLINE_WIDTH);
	platform.setPoint(0 ,sf::Vector2f(0,0));
	platform.setPoint(1, sf::Vector2f(config.xOffset() + .1, 0));
	platform.setPoint(2,
			sf::Vector2f(config.xOffset(), config.floor() + config.initialHeight()));
	platform.setPoint(3,
			sf::Vector2f(0, config.floor() + config.initialHeight()));
	platform.setPosition(
			sf::Vector2f(0, viewHeight - config.floor() - config.initialHeight()));



	sf::Clock clock;
	float t; //time
	unsigned run = 0;
	sf::Event event;

	while (window.isOpen())
	{

		t = clock.getElapsedTime().asSeconds() / 2;

		while (window.pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
				{
					if (event.key.code == sf::Keyboard::R) {
						run = 0;
						clock.restart();
					}
					break;
				}
				default:
					break;
			}
		}

		window.clear(SIMULATION_COLOR_SKYBLUE);

		auto normalPos = getProjectilePosition(config, t) +
				sf::Vector2f(config.xOffset(), config.floor());

		circle.setPosition(normalPos.x - circle.getRadius(),
				viewHeight - normalPos.y - circle.getRadius());

//		if (t > 3)
		if (circle.getPosition().y > viewHeight + 1)
		{
			run++;
			std::cout << "Starting run " << run << std::endl;
			clock.restart();
			continue;
		}

		auto magVX = cosDeg(config.initialAngle()) * config.initialVelocity();
		auto magVY = (sinDeg(config.initialAngle()) * config.initialVelocity())
				+ config.gravity() * t;

		window.draw(ground);
		window.draw(platform);

		switch(run) //Vectors
		{
		case 0: // Clear
			break;
		case 1: // Velocity Components
			//Horizontal Velocity
			drawArrow(window,
					sf::Vector2f(normalPos.x,
							viewHeight - normalPos.y),
							0,
					magVX * .2);
			drawArrow(window,
					sf::Vector2f(normalPos.x,
							viewHeight - normalPos.y),
					M_PIl/2,
					magVY * .2);
			break;
		case 2:
			drawArrow(window,
								sf::Vector2f(normalPos.x,
										viewHeight - normalPos.y),
								atan2(magVY, magVX),
								std::sqrt(std::pow(magVX, 2) + std::pow(magVY, 2)) * .2);
						break;
		case 3:
			drawArrow(window,
					sf::Vector2f(normalPos.x,
							viewHeight - normalPos.y),
					M_PIl/2,
					config.gravity() * .1);

		};

		window.draw(circle);
		window.display();
	}

	return 0;
}
