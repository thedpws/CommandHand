/********************************************************************************
** Form generated from reading UI file 'QtGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUI_H
#define UI_QTGUI_H

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

class Ui_QtGUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGUIClass)
    {
        if (QtGUIClass->objectName().isEmpty())
            QtGUIClass->setObjectName(QStringLiteral("QtGUIClass"));
        QtGUIClass->resize(600, 400);
        menuBar = new QMenuBar(QtGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGUIClass->setStatusBar(statusBar);

        retranslateUi(QtGUIClass);

        QMetaObject::connectSlotsByName(QtGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGUIClass)
    {
        QtGUIClass->setWindowTitle(QApplication::translate("QtGUIClass", "QtGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGUIClass: public Ui_QtGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUI_H
