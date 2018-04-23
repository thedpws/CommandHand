#include "qtgui.h"

QtGUI::QtGUI(QWidget *parent): 
	QMainWindow(parent)
	//,ui(new GUI::QtGUI)
{
	ui.setupUi(this);

	// Maximize window on start
	this->setWindowState(Qt::WindowMaximized);

	// Start Camera Feed
	capture.open(0);

	// Check if sucessful
	if (!capture.isOpened() == true) {
		// ui.  ->appendPlainText("Error: Camera Error!");
		return;
	}

	// Set initial time
	ui.LoopValue->appendPlainText(QString("20"));

	/*
	// Timer for UI responsivness
	tmrTimer = new QTimer(this);
	connect(tmrTimer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));
	tmrTimer->start(ui.LoopValue->toPlainText().toInt()); //ui->txtLoopTime->toPlainText().toInt() msec
	*/

	// Set slider initial values
	ui.RedMinSlider->setSliderPosition(0);
	ui.RedMaxSlider->setSliderPosition(255);
	ui.GreenMinSlider->setSliderPosition(0);
	ui.GreenMaxSlider->setSliderPosition(255);
	ui.BlueMinSlider->setSliderPosition(0);
	ui.BlueMaxSlider->setSliderPosition(255);


}

void QtGUI::processFrameAndUpdateGUI(cv::Mat* raw, cv::Mat* processed)
{
	capture.read(raw);
	// Check if successfully stored
	if (raw->empty() || processed->empty())
	{
		return;
	}

	// OpenCV to QImage datatype to display on labels
	cv::cvtColor(*raw, *raw, CV_BGR2RGB);
	QImage qimgOriginal((uchar*)raw->data, raw->cols, raw->rows, raw->step, QImage::Format_RGB888); // for color images
	QImage qimgProcessed((uchar*)processed->data, processed->cols, processed->rows, processed->step, QImage::Format_RGB888); // for grayscale images

	// Update images on GUI
	ui.RawVideo->setPixmap(QPixmap::fromImage(qimgOriginal));
	ui.ProcessedVideo->setPixmap(QPixmap::fromImage(qimgProcessed));
}

void QtGUI::on_PauseButton_clicked()
{
	if (tmrTimer->isActive() == true) // timer is running
	{ 
		tmrTimer->stop();
		ui.PauseButton->setText("Resume");
	}
	else 
	{
		tmrTimer->start(ui.LoopValue->toPlainText().toInt());
		ui.PauseButton->setText("Pause");
	}
}

bool QtGUI::eventFilter(QObject *object, QEvent *event)
{
	return true;
}
