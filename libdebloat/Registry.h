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
 * Registry.h
 *
 *  Created on: Jul 5, 2013
 *      Author: wweber
 */

#ifndef REGISTRY_H_
#define REGISTRY_H_

#include <Windows.h>
#include <vector>
#include <string>

/**
 * Get a value from the registry
 * @param pRoot The root key
 * @param pKey The name of the key to query
 * @param pValue The name of the value to query
 * @param pData Pointer to where the data will be stored
 * @param pSize The size available in pData
 */
void getRegistryKeyValue(HKEY pRoot, const char* pKey, const char* pValue,
		void* pData, int* pSize);

/**
 * Sets a registry key value
 * @param pRoot The root key
 * @param pKey The name of the subkey
 * @param pValue The name of the value to set
 * @param pType The type of the value to set. See Windows defines.
 * @param pData Pointer to the data to copy
 * @param pSize The size of the data to copy
 */
void setRegistryKeyValue(HKEY pRoot, const char* pKey, const char* pValue,
		int pType, const void* pData, int pSize);

/**
 * Get a list of registry values in a key.
 * @param pRoot The root key
 * @param pKey The name of the subkey
 * @param pMisc Additional flags. Mainly used for registry redirection
 * @return
 */
std::vector<std::string> getRegistryValues(HKEY pRoot, const char* pKey,
		int pMisc = 0);

/**
 * Delete a registry value
 * @param pRoot The root key
 * @param pKey The key to operate on
 * @param pValue The name of the value to delete
 * @param pMisc Additional flags. Mainly used for registry redirection
 */
void deleteRegistryValue(HKEY pRoot, const char* pKey, const char* pValue,
		int pMisc = 0);

#endif /* REGISTRY_H_ */
