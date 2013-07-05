/*
 * PackageManager.cpp
 *
 *  Created on: Jul 4, 2013
 *      Author: wweber
 */

#include "PackageManager.h"
#include "RunProcess.h"
#include <cstdio>

PackageManager::PackageManager()
{
	// TODO Auto-generated constructor stub

}

PackageManager::~PackageManager()
{
	// TODO Auto-generated destructor stub
}

void PackageManager::scanPackages()
{
	std::string res = runProcess("dism /Online /Get-Packages", "");

	mPackages.clear();

	Package current = Package();
	int cpos = 0;
	for (;;)
	{
		int pos = res.find("\r\n", cpos);
		if (pos == std::string::npos)
			break; //out

		std::string line = res.substr(cpos, pos - cpos);

		//search line
		const std::string nameLine = "Package Identity : ";
		const std::string stateLine = "State : ";
		const std::string typeLine = "Release Type : ";

		if (line.find(nameLine) != std::string::npos)
		{
			current.name = line.substr(nameLine.size());
		}
		else if (line.find(stateLine) != std::string::npos)
		{
			current.state = line.substr(stateLine.size());
		}
		else if (line.find(typeLine) != std::string::npos)
		{
			current.type = line.substr(typeLine.size());
		}
		else if (line.compare("") == 0)
		{
			if (current.name.size() > 0)
			{
				mPackages.push_back(current);
				current = Package();
			}
		}

		cpos = pos + 2;
	}
}

void PackageManager::scanFeatures()
{
	std::string res = runProcess("dism /Online /Get-Features", "");

	mFeatures.clear();

	Feature current = Feature();

	int cpos = 0;
	for (;;)
	{
		int pos = res.find("\r\n", cpos);
		if (pos == std::string::npos)
			break;

		std::string line = res.substr(cpos, pos - cpos);

		//check line
		const std::string nameLine = "Feature Name : ";
		const std::string stateLine = "State : ";

		if (line.find(nameLine) != std::string::npos)
		{
			current.name = line.substr(nameLine.size());
		}
		else if (line.find(stateLine) != std::string::npos)
		{
			current.state = line.substr(stateLine.size());
		}
		else if (line.size() == 0)
		{
			if (current.name.size() > 0)
			{
				mFeatures.push_back(current);
				current = Feature();
			}
		}

		cpos = pos + 2;
	}
}

void PackageManager::setFeatureEnabled(const std::string& pName, bool pEnabled)
{
	std::string cmd("dism /NoRestart /Online ");

	if (pEnabled)
	{
		cmd += "/Enable-Feature ";
	}
	else
	{
		cmd += "/Disable-Feature ";
	}

	cmd += "/FeatureName:";
	cmd += pName;

	runProcess(cmd, "");
}

void PackageManager::removePackage(const std::string& pName)
{
	std::string cmd("dism /NoRestart /Online /Remove-Package /PackageName:");
	cmd += pName;

	runProcess(cmd, "");
}

void PackageManager::cleanupServicePack()
{
	runProcess("dism /NoRestart /Online /Cleanup-Image /spsuperseded /hidesp", "");
}
