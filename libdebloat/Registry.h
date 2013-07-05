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

void getRegistryKeyValue(HKEY pRoot, const char* pKey, const char* pValue,
		void* pData, int* pSize);
void setRegistryKeyValue(HKEY pRoot, const char* pKey, const char* pValue,
		int pType, const void* pData, int pSize);

std::vector<std::string> getRegistryValues(HKEY pRoot, const char* pKey);

void deleteRegistryValue(HKEY pRoot, const char* pKey, const char* pValue);

#endif /* REGISTRY_H_ */
