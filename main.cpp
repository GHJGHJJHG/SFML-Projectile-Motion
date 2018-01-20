/*
 * main.cpp
 *
 *  Created on: Dec 25, 2017
 *      Author: Daniel Indictor
 */

#define CONFIG_PATH "/tmp/config.cfg"

#include <cstdlib>
#include <iostream>
//TODO: figure out how to remove "experimental"
#include <experimental/filesystem>

#include <SFML/Graphics.hpp>

#include "config.hpp"
#include "simulation.hpp"

bool getConfig(Config*& config, const fs::path& path) {
	try
	{
		config = new Config(path);
		return true;
	}
	catch (const Config::FileIOException& e)
	{
		std::cout << "File IO Exception. Could not be overcome.\n";
	}
	catch (const Config::ParseException& e)
	{
		std::cout << "Parse exception at file: "
		          << e.getFile()
		          << " line "
		          << e.getLine()
		          << '\n';
	}
	catch (const Config::SettingNotFoundException& e)
	{
		std::cout << "Setting not found: "
		          << e.getPath()
		          << '\n';
	}
	catch (const Config::SettingNameException& e)
	{
		//Deal with SettingNameException and SettingTypeException ;
	}
	catch (const Config::SettingTypeException& e)
	{
		std::cout << "Setting "
		          << e.what()
		          << " at file: "
		          << e.getPath();
	}
	return false;
}

int main()
{
	Config* config;
	if (!getConfig(config, CONFIG_PATH))
	{
		return EXIT_FAILURE;
	}

	return playSimulation(*config);
}
