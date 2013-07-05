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
