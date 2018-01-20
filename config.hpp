/*
 * config.hpp
 *
 *  Created on: Dec 25, 2017
 *      Author: Daniel Indictor
 */

#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#define CONFIG_FRAMERATE_DISABLED -1
#define CONFIG_FRAMERATE_VSYNC 0

#include <libconfig.h++>

#include <iostream> //cerr
#include <experimental/filesystem> //TODO: REMOVE EXPERIMENTAL (somehow)

namespace fs = std::experimental::filesystem;


class Config : private libconfig::Config {
public:

	typedef unsigned int Resolution; //unsigned int as used in SFML code.
	typedef libconfig::ConfigException ConfigException;
	typedef libconfig::FileIOException FileIOException;
	typedef libconfig::ParseException ParseException;
	typedef libconfig::SettingNotFoundException SettingNotFoundException;
	typedef libconfig::SettingNameException SettingNameException;
	typedef libconfig::SettingTypeException SettingTypeException ;

protected:

	Resolution    mWindowWidth;
	Resolution    mWindowHeight;
	int           mVersion;
	std::string   mWindowName;
	int           mFrameRateLimit;
	double        mViewWidth;
	double        mViewHeight;
	double        mInitialAngle;
	double        mInitialVelocity;
	double        mInitialHeight;
	double        mGravity;
	double        mFloor;
	double        mXOffset;

public:

	Config(const fs::path& path);

	Resolution windowWidth() const;
	Resolution windowHeight() const;
	int version() const;
	std::string windowName() const;
	int frameRateLimit() const;
	double viewHeight() const;
	double viewWidth() const;
	double initialAngle() const;
	double initialVelocity() const;
	double initialHeight() const;
	double gravity() const;
	double floor() const;
	double xOffset() const;
};



#endif /* CONFIG_HPP_ */
