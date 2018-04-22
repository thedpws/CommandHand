#include "CommandHandGui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CommandHandGui w;
	w.show();
	return a.exec();
}
