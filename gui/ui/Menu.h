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
			mMenu(pMenu)
	{

	}

protected:
	typedef std::set<std::string> FunctionList;
	Menu* mMenu;
	FunctionList mFuncs;

	void disableFeatures();
	void disableServices();
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

protected:
	Ui_menu mUi;
	QThread mWorkThread;
	Uninstaller* mUninstaller;
};

#endif /* MENU_H_ */
