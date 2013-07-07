/*
 * Menu.cpp
 *
 *  Created on: Jul 6, 2013
 *      Author: wweber
 */

#include "ui/Menu.h"
#include "FeatureUninstaller.h"

Menu::Menu()
{
	mUi.setupUi(this);
}

Menu::~Menu()
{

}

void Menu::apply()
{
	//disable all controls (i think)
	setEnabled(false);

	//TODO: thread this out

	//build list of functionalities to remove

	std::list<const char*> list;

	if (mUi.disable_xps->isChecked())
		list.push_back("xps");
	if (mUi.disable_gadgets->isChecked())
		list.push_back("gadgets");
	if (mUi.disable_tablet->isChecked())
		list.push_back("tablet");
	if (mUi.disable_dotNet->isChecked())
		list.push_back("dotnet");
	if (mUi.disable_search->isChecked())
		list.push_back("search");
	if (mUi.disable_games->isChecked())
		list.push_back("games");
	if (mUi.disable_printing->isChecked())
		list.push_back("printing");
	if (mUi.disable_ie->isChecked())
		list.push_back("ie");
	if (mUi.disable_media->isChecked())
		list.push_back("media");
	if (mUi.disable_homegroup->isChecked())
		list.push_back("homegroup");
	if (mUi.disable_sharing->isChecked())
		list.push_back("sharing");
	if (mUi.disable_fax->isChecked())
		list.push_back("fax");
	if (mUi.disable_remote->isChecked())
		list.push_back("remote");
	if (mUi.disable_bluetooth->isChecked())
		list.push_back("bluetooth");

	//add services if requested
	if (mUi.disable_services->isChecked())
		list.push_back("none");

	//remove features
	uninstallFeatures(list);

	//disable services
	disableServices(list);

	//now close
	close();
}
