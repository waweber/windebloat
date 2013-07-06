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
	{"Internet-Explorer-Optional-x86",		"ie"}, //not sure about this one
};

#endif
