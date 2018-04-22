#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CommandHandGui.h"

class CommandHandGui : public QMainWindow
{
	Q_OBJECT

public:
	CommandHandGui(QWidget *parent = Q_NULLPTR);

private:
	Ui::CommandHandGuiClass ui;
};
