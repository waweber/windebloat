/*
 * Menu.cpp
 *
 *  Created on: Jul 6, 2013
 *      Author: wweber
 */

#include "ui/Menu.h"
#include <cstdio>

Menu::Menu()
{
	mUi.setupUi(this);
}

Menu::~Menu()
{

}

void Menu::apply()
{
	printf("Apply button pressed.\n");
}
