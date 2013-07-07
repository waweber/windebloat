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

#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

struct Functionality
{
	const char* name;
	const char* description;
};

const Functionality gFunctionalities[] =
{
	{"xps",			"XPS Documents"},
	{"gadgets",		"Windows Gadgets"},
	{"tablet",		"Tablet PC components"},
	{"dotnet",		".NET Framework"},
	{"search",		"Windows Search"},
	{"games",		"Windows Games"},
	{"printing",	"Printing Services"},
	{"ie",			"Internet Exploder"},
	{"media",		"Windows Media"},
	{"homegroup",	"Homegroup"},
	{"sharing",		"File Sharing"},
	{"fax",			"Fax Machines"},
	{"remote",		"Remote Desktop"},
	{"bluetooth",	"Bluetooth"},
};

const int gNumFunctionalities = sizeof(gFunctionalities) / sizeof(Functionality);

#endif
