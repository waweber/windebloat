/*
 * FeatureUninstaller.h
 *
 *  Created on: Jul 6, 2013
 *      Author: wweber
 */

#ifndef FEATUREUNINSTALLER_H_
#define FEATUREUNINSTALLER_H_

/**
 * @file
 * Contains declarations for uninstall functions
 */

/**
 * Uninstalls features that provide certain functionalities
 * @param pFuncs The list of functionalities
 */
void uninstallFeatures(const std::list<const char*>& pFuncs);

/**
 * Disable services associated with a certain functionality.
 * @param pFuncs The list of functionalities
 */
void disableServices(const std::list<const char*> pFuncs);


#endif /* FEATUREUNINSTALLER_H_ */
