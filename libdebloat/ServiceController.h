/*
 * ServiceController.h
 *
 *  Created on: Jul 3, 2013
 *      Author: wweber
 */

#ifndef SERVICECONTROLLER_H_
#define SERVICECONTROLLER_H_

#include <Windows.h>

/**
 * Allows the modification of the startup types of services.
 */
class ServiceController
{
public:
	enum State
	{
		DISABLED, MANUAL, AUTOMATIC,
	};

	/**
	 * Create a new service controller.
	 */
	ServiceController();
	virtual ~ServiceController();

	/**
	 * Change the service's startup type.
	 * @param pService The name of the service to modify.
	 * @param pState The new startup type.
	 */
	void changeServiceType(const char* pService, int pState);

protected:
	SC_HANDLE mController;
};

#endif /* SERVICECONTROLLER_H_ */
