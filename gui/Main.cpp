#include <QApplication>
#include "ui_menu.h"

int main(int argc, char** argv)
{
	QApplication q(argc, argv);
	QMainWindow mw;
	Ui::menu m;
	m.setupUi(&mw);
	mw.show();

	return q.exec();
}
