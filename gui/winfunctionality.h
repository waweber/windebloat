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
