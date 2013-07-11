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
