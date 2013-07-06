/*
 * Menu.h
 *
 *  Created on: Jul 6, 2013
 *      Author: wweber
 */

#ifndef MENU_H_
#define MENU_H_

#include "ui_menu.h"

class Menu: public QMainWindow
{

Q_OBJECT

public:
	Menu();
	virtual ~Menu();

public slots:
	void apply();

protected:
	Ui_menu mUi;
};

#endif /* MENU_H_ */
