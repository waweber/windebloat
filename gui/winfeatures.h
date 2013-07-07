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

#ifndef FEATURES_H
#define FEATURES_H

#include "winfunctionality.h"

struct Feature
{
	const char* name;
	const char* function;
};

const Feature gFeatures[] = 
{
	{"WindowsGadgetPlatform",				"gadgets"},
	{"InboxGames",							"games"},
	{"More Games",							"games"},
	{"Internet Games",						"games"},
	{"WindowsMediaPlayer",					"media"},
	{"MediaCenter",							"media"},
	{"OpticalMediaDisc",					"media"},
	{"NetFx3",								"dotnet"},
	{"TabletPCOC",							"tablet"},
	{"Printing-Foundation-Features",		"printing"},
	{"FaxServicesClientPackage",			"fax"},
	{"Xps-Foundation-Xps-Viewer",			"xps"},
	{"Printing-XPSServices-Features",		"xps"},
	{"SearchEngine-Client-Package"		,	"search"},
	{"Internet-Explorer-Optional-amd64",	"ie"},
	{"Internet-Explorer-Optional-x86",		"ie"},
};

const int gNumFeatures = sizeof(gFeatures) / sizeof(Feature);

#endif
