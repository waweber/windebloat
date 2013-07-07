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
 * Menu.h
 *
 *  Created on: Jul 6, 2013
 *      Author: wweber
 */

#ifndef MENU_H_
#define MENU_H_

#include "ui_menu.h"
#include <set>
#include <QThread>

class Menu;

class Uninstaller: public QObject
{
Q_OBJECT
public slots:
	void doUninstall();

signals:
	void onComplete();
	void progress(float pPct, std::string pText);

public:
	Uninstaller(Menu* pMenu) :
			mMenu(pMenu), mProgress(0), mJobs(0)
	{

	}

protected:
	typedef std::set<std::string> FunctionList;
	Menu* mMenu;
	FunctionList mFuncs;
	int mJobs;
	int mProgress;

	void disableFeatures();
	void disableServices();
	void clearStartupPrograms();
	void setUsefulOptions();
};

class Menu: public QMainWindow
{
Q_OBJECT
public:
	Menu();
	virtual ~Menu();

	Ui_menu& getUi()
	{
		return mUi;
	}

public slots:
	void apply();
	void setProgress(float pPct, std::string pText);
	void finishUp();
	bool close();

protected:
	Ui_menu mUi;
	QThread mWorkThread;
	Uninstaller* mUninstaller;
};

#endif /* MENU_H_ */
