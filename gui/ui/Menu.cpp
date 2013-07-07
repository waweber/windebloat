/*
 * Menu.cpp
 *
 *  Created on: Jul 6, 2013
 *      Author: wweber
 */

#include "ui/Menu.h"
#include "winfeatures.h"
#include "winservices.h"
#include <QThread>

void Uninstaller::doUninstall()
{
	//build list of functionalities to remove
	if (mMenu->getUi().disable_xps->isChecked())
		mFuncs.insert("xps");
	if (mMenu->getUi().disable_gadgets->isChecked())
		mFuncs.insert("gadgets");
	if (mMenu->getUi().disable_tablet->isChecked())
		mFuncs.insert("tablet");
	if (mMenu->getUi().disable_dotNet->isChecked())
		mFuncs.insert("dotnet");
	if (mMenu->getUi().disable_search->isChecked())
		mFuncs.insert("search");
	if (mMenu->getUi().disable_games->isChecked())
		mFuncs.insert("games");
	if (mMenu->getUi().disable_printing->isChecked())
		mFuncs.insert("printing");
	if (mMenu->getUi().disable_ie->isChecked())
		mFuncs.insert("ie");
	if (mMenu->getUi().disable_media->isChecked())
		mFuncs.insert("media");
	if (mMenu->getUi().disable_homegroup->isChecked())
		mFuncs.insert("homegroup");
	if (mMenu->getUi().disable_sharing->isChecked())
		mFuncs.insert("sharing");
	if (mMenu->getUi().disable_fax->isChecked())
		mFuncs.insert("fax");
	if (mMenu->getUi().disable_remote->isChecked())
		mFuncs.insert("remote");
	if (mMenu->getUi().disable_bluetooth->isChecked())
		mFuncs.insert("bluetooth");

	//add services if requested
	if (mMenu->getUi().disable_services->isChecked())
		mFuncs.insert("none");

	//remove features
	disableFeatures();

	//disable services
	disableServices();

	emit onComplete();
}

void Uninstaller::disableFeatures()
{
	//build feature list
	PackageManager pkg;
	pkg.scanFeatures();

	//enumerate targeted functionalities
	for (FunctionList::const_iterator itr = mFuncs.begin(); itr != mFuncs.end();
			++itr)
	{
		//enumerate features
		for (int i = 0; i < gNumFeatures; ++i)
		{
			if (*itr != gFeatures[i].function)
				continue; //not needed

			//check if installed
			for (PackageManager::FeatureList::const_iterator itr2 =
					pkg.getFeatures().begin(); itr2 != pkg.getFeatures().end();
					++itr2)
			{
				if (itr2->name == gFeatures[i].name)
				{
					//uninstall only enabled features
					if (itr2->state == "Enabled")
					{
						try
						{
							//do it
							emit progress(-1,
									std::string("Removing ") + itr2->name);
							pkg.setFeatureEnabled(itr2->name, false);
						} catch (const std::exception&)
						{

						}
					}
					else
					{
						break; //don't need to keep checking
					}
				}
			}
		}
	}
}

void Uninstaller::disableServices()
{
	ServiceController svc;

	//iterate targeted functions
	for (FunctionList::const_iterator itr = mFuncs.begin(); itr != mFuncs.end();
			++itr)
	{
		//enumerate services
		for (int i = 0; i < gNumServices; ++i)
		{
			if (*itr != gServices[i].function)
				continue; //not targeted

			//disable
			try
			{
				emit progress(-1,
						std::string("Disabling ") + gServices[i].name);
				svc.changeServiceType(gServices[i].name,
						ServiceController::DISABLED);
			} catch (const std::exception&)
			{

			}
		}
	}
}

Menu::Menu() :
		mUninstaller(NULL)
{
	mUi.setupUi(this);
}

Menu::~Menu()
{

}

void Menu::setProgress(float pPct, const std::string& pText)
{
	if (pText != "")
		mUi.progress_text->setText(QString::fromStdString(pText));

	if (pPct >= 0)
		mUi.progress->setValue(pPct * 100);
}

void Menu::finishUp()
{
	if (mUninstaller)
		delete mUninstaller;
	mUninstaller = NULL;

	close();
}

void Menu::apply()
{
	//disable all controls (i think)
	setEnabled(false);

	Uninstaller* u = new Uninstaller(this);
	u->moveToThread(&mWorkThread);

	QObject::connect(&mWorkThread, SIGNAL(started()), u, SLOT(doUninstall()));
	QObject::connect(u, SIGNAL(progress(float, const std::string&)), this,
			SLOT(setProgress(float, const std::string&)));
	QObject::connect(u, SIGNAL(onComplete()), this, SLOT(finishUp()));
	mWorkThread.start();
}

