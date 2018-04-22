#include "QtGUI.h"

QtGUI::QtGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// Maximize window on start
	this->setWindowState(Qt::WindowMaximized);
}
