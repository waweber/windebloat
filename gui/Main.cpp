
#include "ui/Menu.h"

int main(int argc, char** argv)
{
	QApplication q(argc, argv);

	qRegisterMetaType<std::string>();

	Menu m;
	m.show();

	return q.exec();
}
