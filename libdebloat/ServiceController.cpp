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
 * ServiceController.cpp
 *
 *  Created on: Jul 3, 2013
 *      Author: wweber
 */

#include "ServiceController.h"
#include <exception>

ServiceController::ServiceController()
{
	mController = OpenSCManager(NULL, NULL, GENERIC_ALL);
}

ServiceController::~ServiceController()
{
	CloseServiceHandle(mController);
}

void ServiceController::changeServiceType(const char* pService, int pState)
{
	SC_HANDLE service = OpenService(mController, pService, GENERIC_ALL);

	if (service == NULL)
	{
		throw std::exception();
	}

	DWORD type = SERVICE_NO_CHANGE;

	switch (pState)
	{
	case DISABLED:
		type = SERVICE_DISABLED;
		break;
	case MANUAL:
		type = SERVICE_DEMAND_START;
		break;
	case AUTOMATIC:
		type = SERVICE_AUTO_START;
		break;
	}

	int res = ChangeServiceConfig(service, SERVICE_NO_CHANGE, type,
	SERVICE_NO_CHANGE,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL);

	CloseServiceHandle(service);
}
