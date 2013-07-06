
#include "ui/Menu.h"

int main(int argc, char** argv)
{
	QApplication q(argc, argv);

	Menu m;
	m.show();

	return q.exec();
}
