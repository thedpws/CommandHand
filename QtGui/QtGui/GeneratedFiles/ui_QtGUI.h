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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGUIClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *RawVideo;
    QLabel *ProcessedVideo;
    QSlider *RedMinSlider;
    QSlider *RedMaxSlider;
    QSlider *GreenMinSlider;
    QSlider *GreenMaxSlider;
    QSlider *BlueMaxSlider;
    QSlider *BlueMinSlider;
    QPlainTextEdit *RedMinValue;
    QPlainTextEdit *RedMaxValue;
    QPlainTextEdit *GreenMinValue;
    QPlainTextEdit *GreenMaxValue;
    QPlainTextEdit *BlueMinValue;
    QPlainTextEdit *BlueMaxValue;
    QLabel *RedMinLabel;
    QLabel *RedMaxLabel;
    QLabel *GreenMinLabel;
    QLabel *GreenMaxLabel;
    QLabel *BlueMinLabel;
    QLabel *BlueMaxLabel;
    QPushButton *PauseButton;
    QLabel *GestureIDLabel;
    QPlainTextEdit *GestureIDValue;
    QPlainTextEdit *GestureCoordValue;
    QLabel *GestureCoordLabel;
    QPlainTextEdit *CursorCoordValue;
    QLabel *CursorCoordLabel;
    QSlider *KSizeSlider;
    QSlider *ThresholdSlider;
    QLabel *KSizeLabel;
    QLabel *ThresholdLabel;
    QPlainTextEdit *KSizeValue;
    QPlainTextEdit *ThresholdValue;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGUIClass)
    {
        if (QtGUIClass->objectName().isEmpty())
            QtGUIClass->setObjectName(QStringLiteral("QtGUIClass"));
        QtGUIClass->resize(1920, 1084);
        centralWidget = new QWidget(QtGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(420, 0, 1491, 781));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        RawVideo = new QLabel(horizontalLayoutWidget);
        RawVideo->setObjectName(QStringLiteral("RawVideo"));

        horizontalLayout->addWidget(RawVideo);

        ProcessedVideo = new QLabel(horizontalLayoutWidget);
        ProcessedVideo->setObjectName(QStringLiteral("ProcessedVideo"));

        horizontalLayout->addWidget(ProcessedVideo);

        RedMinSlider = new QSlider(centralWidget);
        RedMinSlider->setObjectName(QStringLiteral("RedMinSlider"));
        RedMinSlider->setGeometry(QRect(30, 30, 160, 22));
        RedMinSlider->setMaximum(255);
        RedMinSlider->setOrientation(Qt::Horizontal);
        RedMaxSlider = new QSlider(centralWidget);
        RedMaxSlider->setObjectName(QStringLiteral("RedMaxSlider"));
        RedMaxSlider->setGeometry(QRect(30, 80, 160, 22));
        RedMaxSlider->setMaximum(255);
        RedMaxSlider->setOrientation(Qt::Horizontal);
        GreenMinSlider = new QSlider(centralWidget);
        GreenMinSlider->setObjectName(QStringLiteral("GreenMinSlider"));
        GreenMinSlider->setGeometry(QRect(30, 129, 160, 22));
        GreenMinSlider->setMaximum(255);
        GreenMinSlider->setOrientation(Qt::Horizontal);
        GreenMaxSlider = new QSlider(centralWidget);
        GreenMaxSlider->setObjectName(QStringLiteral("GreenMaxSlider"));
        GreenMaxSlider->setGeometry(QRect(30, 180, 161, 21));
        GreenMaxSlider->setMaximum(255);
        GreenMaxSlider->setOrientation(Qt::Horizontal);
        BlueMaxSlider = new QSlider(centralWidget);
        BlueMaxSlider->setObjectName(QStringLiteral("BlueMaxSlider"));
        BlueMaxSlider->setGeometry(QRect(30, 280, 160, 22));
        BlueMaxSlider->setMaximum(255);
        BlueMaxSlider->setOrientation(Qt::Horizontal);
        BlueMinSlider = new QSlider(centralWidget);
        BlueMinSlider->setObjectName(QStringLiteral("BlueMinSlider"));
        BlueMinSlider->setGeometry(QRect(30, 230, 160, 22));
        BlueMinSlider->setMaximum(255);
        BlueMinSlider->setOrientation(Qt::Horizontal);
        RedMinValue = new QPlainTextEdit(centralWidget);
        RedMinValue->setObjectName(QStringLiteral("RedMinValue"));
        RedMinValue->setGeometry(QRect(210, 20, 91, 41));
        RedMaxValue = new QPlainTextEdit(centralWidget);
        RedMaxValue->setObjectName(QStringLiteral("RedMaxValue"));
        RedMaxValue->setGeometry(QRect(210, 70, 91, 41));
        GreenMinValue = new QPlainTextEdit(centralWidget);
        GreenMinValue->setObjectName(QStringLiteral("GreenMinValue"));
        GreenMinValue->setGeometry(QRect(210, 120, 91, 41));
        GreenMaxValue = new QPlainTextEdit(centralWidget);
        GreenMaxValue->setObjectName(QStringLiteral("GreenMaxValue"));
        GreenMaxValue->setGeometry(QRect(210, 170, 91, 41));
        BlueMinValue = new QPlainTextEdit(centralWidget);
        BlueMinValue->setObjectName(QStringLiteral("BlueMinValue"));
        BlueMinValue->setGeometry(QRect(210, 220, 91, 41));
        BlueMaxValue = new QPlainTextEdit(centralWidget);
        BlueMaxValue->setObjectName(QStringLiteral("BlueMaxValue"));
        BlueMaxValue->setGeometry(QRect(210, 270, 91, 41));
        RedMinLabel = new QLabel(centralWidget);
        RedMinLabel->setObjectName(QStringLiteral("RedMinLabel"));
        RedMinLabel->setGeometry(QRect(310, 20, 91, 41));
        QFont font;
        font.setPointSize(14);
        RedMinLabel->setFont(font);
        RedMaxLabel = new QLabel(centralWidget);
        RedMaxLabel->setObjectName(QStringLiteral("RedMaxLabel"));
        RedMaxLabel->setGeometry(QRect(310, 70, 91, 41));
        RedMaxLabel->setFont(font);
        GreenMinLabel = new QLabel(centralWidget);
        GreenMinLabel->setObjectName(QStringLiteral("GreenMinLabel"));
        GreenMinLabel->setGeometry(QRect(310, 120, 91, 41));
        GreenMinLabel->setFont(font);
        GreenMaxLabel = new QLabel(centralWidget);
        GreenMaxLabel->setObjectName(QStringLiteral("GreenMaxLabel"));
        GreenMaxLabel->setGeometry(QRect(310, 170, 91, 41));
        GreenMaxLabel->setFont(font);
        BlueMinLabel = new QLabel(centralWidget);
        BlueMinLabel->setObjectName(QStringLiteral("BlueMinLabel"));
        BlueMinLabel->setGeometry(QRect(310, 220, 91, 41));
        BlueMinLabel->setFont(font);
        BlueMaxLabel = new QLabel(centralWidget);
        BlueMaxLabel->setObjectName(QStringLiteral("BlueMaxLabel"));
        BlueMaxLabel->setGeometry(QRect(310, 270, 91, 41));
        BlueMaxLabel->setFont(font);
        PauseButton = new QPushButton(centralWidget);
        PauseButton->setObjectName(QStringLiteral("PauseButton"));
        PauseButton->setGeometry(QRect(1140, 820, 361, 141));
        GestureIDLabel = new QLabel(centralWidget);
        GestureIDLabel->setObjectName(QStringLiteral("GestureIDLabel"));
        GestureIDLabel->setGeometry(QRect(1540, 832, 61, 21));
        GestureIDValue = new QPlainTextEdit(centralWidget);
        GestureIDValue->setObjectName(QStringLiteral("GestureIDValue"));
        GestureIDValue->setGeometry(QRect(1614, 820, 91, 41));
        QFont font1;
        font1.setPointSize(16);
        GestureIDValue->setFont(font1);
        GestureCoordValue = new QPlainTextEdit(centralWidget);
        GestureCoordValue->setObjectName(QStringLiteral("GestureCoordValue"));
        GestureCoordValue->setGeometry(QRect(1614, 868, 91, 41));
        GestureCoordLabel = new QLabel(centralWidget);
        GestureCoordLabel->setObjectName(QStringLiteral("GestureCoordLabel"));
        GestureCoordLabel->setGeometry(QRect(1520, 880, 81, 21));
        CursorCoordValue = new QPlainTextEdit(centralWidget);
        CursorCoordValue->setObjectName(QStringLiteral("CursorCoordValue"));
        CursorCoordValue->setGeometry(QRect(1614, 918, 91, 41));
        CursorCoordLabel = new QLabel(centralWidget);
        CursorCoordLabel->setObjectName(QStringLiteral("CursorCoordLabel"));
        CursorCoordLabel->setGeometry(QRect(1520, 930, 81, 21));
        QFont font2;
        font2.setPointSize(8);
        CursorCoordLabel->setFont(font2);
        KSizeSlider = new QSlider(centralWidget);
        KSizeSlider->setObjectName(QStringLiteral("KSizeSlider"));
        KSizeSlider->setGeometry(QRect(120, 530, 61, 231));
        KSizeSlider->setMaximum(255);
        KSizeSlider->setOrientation(Qt::Vertical);
        ThresholdSlider = new QSlider(centralWidget);
        ThresholdSlider->setObjectName(QStringLiteral("ThresholdSlider"));
        ThresholdSlider->setGeometry(QRect(231, 529, 61, 231));
        ThresholdSlider->setMaximum(255);
        ThresholdSlider->setOrientation(Qt::Vertical);
        KSizeLabel = new QLabel(centralWidget);
        KSizeLabel->setObjectName(QStringLiteral("KSizeLabel"));
        KSizeLabel->setGeometry(QRect(120, 430, 61, 41));
        KSizeLabel->setFont(font1);
        ThresholdLabel = new QLabel(centralWidget);
        ThresholdLabel->setObjectName(QStringLiteral("ThresholdLabel"));
        ThresholdLabel->setGeometry(QRect(210, 430, 101, 41));
        ThresholdLabel->setFont(font1);
        KSizeValue = new QPlainTextEdit(centralWidget);
        KSizeValue->setObjectName(QStringLiteral("KSizeValue"));
        KSizeValue->setGeometry(QRect(100, 480, 101, 51));
        ThresholdValue = new QPlainTextEdit(centralWidget);
        ThresholdValue->setObjectName(QStringLiteral("ThresholdValue"));
        ThresholdValue->setGeometry(QRect(210, 480, 101, 51));
        QtGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1920, 21));
        QtGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGUIClass->setStatusBar(statusBar);

        retranslateUi(QtGUIClass);

        QMetaObject::connectSlotsByName(QtGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGUIClass)
    {
        QtGUIClass->setWindowTitle(QApplication::translate("QtGUIClass", "QtGUI", nullptr));
        RawVideo->setText(QString());
        ProcessedVideo->setText(QString());
        RedMinLabel->setText(QApplication::translate("QtGUIClass", "Red Min", nullptr));
        RedMaxLabel->setText(QApplication::translate("QtGUIClass", "Red Max", nullptr));
        GreenMinLabel->setText(QApplication::translate("QtGUIClass", "Green Min", nullptr));
        GreenMaxLabel->setText(QApplication::translate("QtGUIClass", "Green Max", nullptr));
        BlueMinLabel->setText(QApplication::translate("QtGUIClass", "Blue Min", nullptr));
        BlueMaxLabel->setText(QApplication::translate("QtGUIClass", "Blue Max", nullptr));
        PauseButton->setText(QApplication::translate("QtGUIClass", "Pause", nullptr));
        GestureIDLabel->setText(QApplication::translate("QtGUIClass", "Gesture ID", nullptr));
        GestureCoordLabel->setText(QApplication::translate("QtGUIClass", "Gesture Coords", nullptr));
        CursorCoordLabel->setText(QApplication::translate("QtGUIClass", "Cursor Coords", nullptr));
        KSizeLabel->setText(QApplication::translate("QtGUIClass", "K-Size", nullptr));
        ThresholdLabel->setText(QApplication::translate("QtGUIClass", "Threshold", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGUIClass: public Ui_QtGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUI_H
