#pragma once

#include <QtWidgets/QMainWindow>
#include <QtCore>
#include "ui_QtGUI.h"
#include <QTimer>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "Windows.h"

#include "Drawer.h"

namespace GUI {
	class QtGUI;
}

class QtGUI : public QMainWindow
{
	Q_OBJECT

public:
	QtGUI(QWidget *parent = Q_NULLPTR);

	bool isPaused();

	int getRMaxValue();

	int getGMaxValue();

	int getBMaxValue();

	int getRMinValue();

	int getGMinValue();

	int getBMinValue();

	int getKSize();

	int getThreshold();

private:
	Ui::QtGUIClass ui;

	// OpenCV Objects
	cv::VideoCapture capture;

	cv::Mat raw;
	cv::Mat processed;


	// Internal Slider Values
	int RMax;

	int RMin;

	int GMax;

	int GMin;

	int BMax;

	int BMin;

	// Internal K-Size and Threshold Values
	int KSize;

	int Threshold;

	// Internal bool for the video feed
	bool isPause;

	// Qt Images
	QImage qImgRaw;

	QImage qimgProcessed;

	// Pointer to push button
	QPushButton *p_PauseButton;

public slots:
	void QtGUI::processFrameAndUpdateGUI(cv::Mat* raw, cv::Mat* processed);

	bool eventFilter(QObject *object, QEvent *event);

private slots:
	void on_PauseButton_clicked();

};
