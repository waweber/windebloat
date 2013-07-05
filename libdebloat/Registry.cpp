/*
 * Registry.cpp
 *
 *  Created on: Jul 5, 2013
 *      Author: wweber
 */

#include "Registry.h"
#include <exception>

void getRegistryKeyValue(HKEY pRoot, const char* pKey, const char* pValue,
		void* pData, int* pSize)
{
	HKEY key;
	int res = RegOpenKeyEx(pRoot, pKey, 0, KEY_READ, &key);
	if (res != ERROR_SUCCESS)
	{
		throw std::exception();
	}

	res = RegQueryValueEx(key, pValue, 0, 0, (LPBYTE) pData, (LPDWORD) pSize);

	RegCloseKey(key);

	if (res != ERROR_SUCCESS)
	{
		throw std::exception();
	}
}

void setRegistryKeyValue(HKEY pRoot, const char* pKey, const char* pValue,
		int pType, const void* pData, int pSize)
{
	HKEY key;
	int res = RegOpenKeyEx(pRoot, pKey, 0, KEY_WRITE, &key);
	if (res != ERROR_SUCCESS)
	{
		throw std::exception();
	}

	res = RegSetValueEx(key, pValue, 0, pType, (const BYTE*) pData, pSize);

	RegCloseKey(key);
	if (res != ERROR_SUCCESS)
	{
		throw std::exception();
	}
}

std::vector<std::string> getRegistryValues(HKEY pRoot, const char* pKey)
{
	std::vector<std::string> values;

	HKEY key;
	int res = RegOpenKeyEx(pRoot, pKey, 0, KEY_READ, &key);
	if (res != ERROR_SUCCESS)
	{
		throw std::exception();
	}

	char name[256];

	int i = 0;
	for (;;)
	{
		int namesize = 256;
		res = RegEnumValue(key, i, name, (LPDWORD) &namesize, NULL, NULL, NULL,
		NULL);
		if (res != ERROR_SUCCESS)
			break;

		values.push_back(name);
		++i;
	}

	RegCloseKey(key);

	return values;
}

void deleteRegistryValue(HKEY pRoot, const char* pKey, const char* pValue)
{
	HKEY key;
	int res = RegOpenKeyEx(pRoot, pKey, 0, KEY_WRITE, &key);
	if (res != ERROR_SUCCESS)
	{
		throw std::exception();
	}

	RegDeleteValue(key, pValue);
	RegCloseKey(key);
}
