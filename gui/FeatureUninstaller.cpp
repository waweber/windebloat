/*
 * FeatureUninstaller.cpp
 *
 *  Created on: Jul 5, 2013
 *      Author: wweber
 */

#include "winfeatures.h"
#include "winservices.h"
#include "libdebloat/ServiceController.h"
#include "libdebloat/PackageManager.h"
#include <list>
#include <string>
#include <cstring>

void uninstallFeatures(const std::list<const char*>& pFuncs)
{
	PackageManager pkg;
	int features = sizeof(gFeatures) / sizeof(Feature);
	for (std::list<const char*>::const_iterator itr = pFuncs.begin();
			itr != pFuncs.end(); ++itr)
	{
		for (int i = 0; i < features; ++i)
		{
			if (strcmp(*itr, gFeatures[i].function) == 0)
			{
				//uninstall
				try
				{
					pkg.setFeatureEnabled(gFeatures[i].name, false);
				} catch (const std::exception&)
				{

				}
			}
		}
	}
}

void disableServices(const std::list<const char*> pFuncs)
{
	ServiceController svc;
	int services = sizeof(gServices) / sizeof(Service);

	for (std::list<const char*>::const_iterator itr = pFuncs.begin();
			itr != pFuncs.end(); ++itr)
	{
		for (int i = 0; i < services; ++i)
		{
			if (strcmp(*itr, gServices[i].function) == 0)
			{
				//disable
				try
				{
					svc.changeServiceType(gServices[i].name,
							ServiceController::DISABLED);
				} catch (const std::exception&)
				{

				}
			}
		}
	}
}
