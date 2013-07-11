/*
 * This file is part of WinDeBloat.
 * 
 * WinDeBloat is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * WinDeBloat is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with WinDeBloat.  If not, see <http://www.gnu.org/licenses/>. 
 */

/*
 * PackageManager.h
 *
 *  Created on: Jul 4, 2013
 *      Author: wweber
 */

#ifndef PACKAGEMANAGER_H_
#define PACKAGEMANAGER_H_

#include <Windows.h>
#include <string>

#include <list>

/**
 * Class that allows adding/removing Windows packages and features.
 * Invokes Dism.exe to run these operations.
 */
class PackageManager
{
public:

	/**
	 * Represents a Package
	 */
	struct Package
	{
		std::string name;
		std::string state;
		std::string type;
	};

	/**
	 * Represents a Feature
	 */
	struct Feature
	{
		std::string name;
		std::string state;
	};

	typedef std::list<Package> PackageList;
	typedef std::list<Feature> FeatureList;

	PackageManager();
	virtual ~PackageManager();

	/**
	 * Retrieve a list of packages on the system.
	 */
	void scanPackages();

	/**
	 * Retrieve a list of features in the system.
	 */
	void scanFeatures();

	/**
	 * Get a list of all found packages.
	 * @return
	 */
	const PackageList& getPackages() const
	{
		return mPackages;
	}

	/**
	 * Get a list of all found features.
	 * @return
	 */
	const FeatureList& getFeatures() const
	{
		return mFeatures;
	}

	/**
	 * Enables or disables a feature.
	 * Many of these will not take effect until next reboot.
	 * @param pName The name of the feature.
	 * @param pEnabled True to enable, false to disable
	 */
	void setFeatureEnabled(const std::string& pName, bool pEnabled);

	/**
	 * Remove a package by name.
	 * @param pName The package to remove
	 */
	void removePackage(const std::string& pName);

	/**
	 * Delete service pack backup files.
	 */
	void cleanupServicePack();

protected:
	PackageList mPackages;
	FeatureList mFeatures;
};

#endif /* PACKAGEMANAGER_H_ */
