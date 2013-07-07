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

#include <set>

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

	typedef std::set<Package> PackageSet;
	typedef std::set<Feature> FeatureSet;

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
	const PackageSet& getPackages() const
	{
		return mPackages;
	}

	/**
	 * Get a list of all found features.
	 * @return
	 */
	const FeatureSet& getFeatures() const
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
	PackageSet mPackages;
	FeatureSet mFeatures;
};

#endif /* PACKAGEMANAGER_H_ */
