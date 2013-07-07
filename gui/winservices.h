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

#ifndef SERVICES_H
#define SERVICES_H

#include "winfunctionality.h"

struct Service
{
	const char* name;
	const char* function;
};

const Service gServices[] =
{
	{"AdobeFlashPlayerUpdateSvc",	"none"}, //adobe update
	{"ALG",							"none"}, //internet connection sharing
	{"SharedAccess",				"none"}, //ICS
	{"AppIDSvc",					"none"}, //applocker or something
	{"AxInstSV",					"none"}, //craptivex
	{"BDESVC",						"none"}, //encraption
	{"BITS",						"none"}, // auto updates!
	{"bthserv",						"bluetooth"}, //bruetoof
	{"CertPropSvc",					"none"}, //certificate propagation
	{"ComSysApp",					"none"}, //com+
	{"HomeGroupListener",			"homegroup"},
	{"HomeGroupProvider",			"homegroup"},
	{"SDRSVC",						"none"}, //win backup
	{"SensrSvc",					"none"}, //adaptive brighness
	{"VaultSvc",					"none"}, //credential manager
	{"WdiSystemHost",				"none"}, //diagnostic system host
	{"WdiServiceHost",				"none"}, //diagnostic host
	{"wercplsupport",				"none"}, //windows problem support
	{"WerSvc",						"none"}, //error reporting
	{"WMPNetworkSvc",				"sharing"}, //media network share
	{"WPCSvc",						"none"}, //parental controls
	{"DPS",							"none"}, //diagnostic policy
	{"iphlpsvc",					"none"}, //ip helper, ipv6 translation, etc
	{"MSiSCSI",						"none"}, //iSCSI
	{"PNRPsvc",						"none"}, //peer name resolution
	{"p2psvcp",						"none"}, //peer
	{"p2pimsvc",					"none"}, //peer
	{"WPDBusEnum",					"none"}, //group policy hw removal
	{"PcaSvc",						"none"}, //compatibility
	{"TermService",					"remote"}, //remote desktop
	{"UmRdpService",				"remote"}, //remote desktop
	{"RemoteRegistry",				"remote"}, //remote registry
	{"RemoteAccess",				"remote"}, //remote access
	{"SessionEnv",					"remote"}, //remote stuff
	{"WebClient",					"none"}, //does this disable winhttp?
	{"WinHttpAutoProxySvc",			"none"}, //winhttp auto proxy svc
	{"Mcx2Svc",						"none"}, //media center extender
	{"NetTcpPortSharing",			"none"}, //tcp port sharing
};

const int gNumServices = sizeof(gServices) / sizeof(Service);

#endif
