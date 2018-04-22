/********************************************************************************
** Form generated from reading UI file 'CommandHandGui.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDHANDGUI_H
#define UI_COMMANDHANDGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommandHandGuiClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CommandHandGuiClass)
    {
        if (CommandHandGuiClass->objectName().isEmpty())
            CommandHandGuiClass->setObjectName(QStringLiteral("CommandHandGuiClass"));
        CommandHandGuiClass->resize(600, 400);
        menuBar = new QMenuBar(CommandHandGuiClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        CommandHandGuiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CommandHandGuiClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CommandHandGuiClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(CommandHandGuiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CommandHandGuiClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CommandHandGuiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CommandHandGuiClass->setStatusBar(statusBar);

        retranslateUi(CommandHandGuiClass);

        QMetaObject::connectSlotsByName(CommandHandGuiClass);
    } // setupUi

    void retranslateUi(QMainWindow *CommandHandGuiClass)
    {
        CommandHandGuiClass->setWindowTitle(QApplication::translate("CommandHandGuiClass", "CommandHandGui", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommandHandGuiClass: public Ui_CommandHandGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDHANDGUI_H
