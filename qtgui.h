#pragma once

#include <QtWidgets/QMainWindow>
#include <QtCore>
#include "ui_QtGUI.h"
#include <QTimer>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "Drawer.h"

namespace GUI {
	class QtGUI;
}

class QtGUI : public QMainWindow
{
	Q_OBJECT

public:
	QtGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGUIClass ui;
	
	// OpenCV Objects
	cv::VideoCapture capture;
	cv::Mat raw;
	cv::Mat processed;

	// QTimer Class- Govern update cycle of GUI
	QTimer *tmrTimer;

	// Qt Images
	QImage qImgRaw;
	QImage qimgProcessed;
	
public slots:
	void QtGUI::processFrameAndUpdateGUI(cv::Mat* raw, cv::Mat* processed);
	bool eventFilter(QObject *object, QEvent *event);

private slots:
	void on_PauseButton_clicked();

};
