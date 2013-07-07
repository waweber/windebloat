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

std::vector<std::string> getRegistryValues(HKEY pRoot, const char* pKey, int pMisc)
{
	std::vector<std::string> values;

	HKEY key;
	int res = RegOpenKeyEx(pRoot, pKey, 0, KEY_READ | pMisc, &key);
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

void deleteRegistryValue(HKEY pRoot, const char* pKey, const char* pValue, int pMisc)
{
	HKEY key;
	int res = RegOpenKeyEx(pRoot, pKey, 0, KEY_WRITE | pMisc, &key);
	if (res != ERROR_SUCCESS)
	{
		throw std::exception();
	}

	RegDeleteValue(key, pValue);
	RegCloseKey(key);
}
