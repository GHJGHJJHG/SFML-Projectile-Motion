/*
 * config.cpp
 *
 *  Created on: Dec 25, 2017
 *      Author: Daniel Indictor
 */

#include "config.hpp"

Config::Config(const fs::path& path)// : path(path)
{
	setAutoConvert(true);

	if (fs::exists(path))
	{
		readFile(path.c_str());
	}
	else
	{
		getRoot().add("version", libconfig::Setting::TypeInt) = 4;

		getRoot().add("window", libconfig::Setting::TypeGroup);
		getRoot()["window"].add("width", libconfig::Setting::TypeInt) = 1280;
		getRoot()["window"].add("height", libconfig::Setting::TypeInt) = 720;
		getRoot()["window"].add("name", libconfig::Setting::TypeString) =
				"The Indictor & Villamor Projectile Motion Simulator";
		getRoot()["window"].add("frameRateLimit",
				libconfig::Setting::TypeInt) = CONFIG_FRAMERATE_VSYNC;

		getRoot().add("view", libconfig::Setting::TypeGroup);
		getRoot()["view"].add("width",
				libconfig::Setting::TypeFloat) = 8;
		getRoot()["view"].add("height",
				libconfig::Setting::TypeFloat) = 4.5;

		getRoot().add("launchParameters", libconfig::Setting::TypeGroup);
		getRoot()["launchParameters"].add("initialAngle",
				libconfig::Setting::TypeFloat) = 45;
		getRoot()["launchParameters"].add("initialVelocity",
				libconfig::Setting::TypeFloat) = 8;
		getRoot()["launchParameters"].add("initialHeight",
				libconfig::Setting::TypeFloat) = 1;
		getRoot()["launchParameters"].add("gravity",
				libconfig::Setting::TypeFloat) = -9.81;
		getRoot()["launchParameters"].add("floor",
				libconfig::Setting::TypeFloat) = .25;
		getRoot()["launchParameters"].add("xOffset",
						libconfig::Setting::TypeFloat) = .25;

		std::cerr << "Writing new configuration file to "
				          << path.string() << '\n';
		writeFile(path.c_str());

	}
	lookupValue("version", mVersion);
	lookupValue("window.width", mWindowWidth);
	lookupValue("window.height", mWindowHeight);
	lookupValue("window.name", mWindowName);
	lookupValue("window.frameRateLimit", mFrameRateLimit);
	lookupValue("view.width", mViewWidth);
	lookupValue("view.height", mViewHeight);
	lookupValue("launchParameters.initialAngle", mInitialAngle);
	lookupValue("launchParameters.initialVelocity", mInitialVelocity);
	lookupValue("launchParameters.initialHeight", mInitialHeight);
	lookupValue("launchParameters.gravity", mGravity);
	lookupValue("launchParameters.floor", mFloor);
	lookupValue("launchParameters.xOffset",mXOffset);
}

Config::Resolution Config::windowWidth() const   { return mWindowWidth;}
Config::Resolution Config::windowHeight() const  { return mWindowHeight;}
int Config::version() const                      { return mVersion;}
std::string Config::windowName() const           { return mWindowName;}
int Config::frameRateLimit() const               { return mFrameRateLimit;}
double Config::viewWidth() const                 { return mViewWidth;}
double Config::viewHeight() const                { return mViewHeight;}
double Config::initialAngle() const              { return mInitialAngle;}
double Config::initialVelocity() const           { return mInitialVelocity;}
double Config::initialHeight() const             { return mInitialHeight;}
double Config::gravity() const                   { return mGravity;}
double Config::floor() const                     { return mFloor;}
double Config::xOffset() const                   { return mXOffset;}
