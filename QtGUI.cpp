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

	// Set slider initial values
	ui.RedMinSlider->setSliderPosition(185);
	ui.RedMaxSlider->setSliderPosition(255);
	ui.GreenMinSlider->setSliderPosition(141);
	ui.GreenMaxSlider->setSliderPosition(255);
	ui.BlueMinSlider->setSliderPosition(105);
	ui.BlueMaxSlider->setSliderPosition(255);
	ui.KSizeSlider->setSliderPosition(20);
	ui.ThresholdSlider->setSliderPosition(62);

	// Initialize internal values
	RMin = 185;
	RMax = 255;
	GMin = 141;
	GMax = 255;
	BMin = 105;
	BMax = 255;
	KSize = 20;
	Threshold = 62;

	// On pause button click call on_PauseButton_clicked
	p_PauseButton = ui.PauseButton;
	connect(p_PauseButton, SIGNAL(clicked()), this, SLOT(on_PauseButton_clicked()));
}

void QtGUI::processFrameAndUpdateGUI(cv::Mat* raw, cv::Mat* processed)
{
	// Check if successfully stored
	if (raw == NULL || raw->empty() || processed == NULL || processed->empty())
	{
		return;
	}

	// OpenCV to QImage datatype to display on labels
	cv::inRange(*processed, cv::Scalar(BMin, GMin, RMin), cv::Scalar(BMax, GMax, RMax), *processed);
	if (this->KSize > 0) cv::blur(*processed, *processed, cv::Size(KSize, KSize));
	if (Threshold > 0) cv::threshold(*processed, *processed, Threshold, 255, 0);
	cv::cvtColor(*raw, *raw, CV_BGR2RGB);
	cv::cvtColor(*processed, *processed, CV_BGR2RGB);
	QImage qimgOriginal((uchar*)raw->data, raw->cols, raw->rows, raw->step, QImage::Format_RGB888); // for color images
	QImage qimgProcessed((uchar*)processed->data, processed->cols, processed->rows, processed->step, QImage::Format_RGB888); // for grayscale images

	// Update images on GUI
	ui.RawVideo->setPixmap(QPixmap::fromImage(qimgOriginal));
	ui.ProcessedVideo->setPixmap(QPixmap::fromImage(qimgProcessed));

	// Update text boxes based on sliders
	ui.RedMaxValue->clear();
	ui.RedMaxValue->appendPlainText(QString::number(ui.RedMaxSlider->value()));
	ui.RedMinValue->clear();
	ui.RedMinValue->appendPlainText(QString::number(ui.RedMinSlider->value()));
	ui.GreenMaxValue->clear();
	ui.GreenMaxValue->appendPlainText(QString::number(ui.GreenMaxSlider->value()));
	ui.GreenMinValue->clear();
	ui.GreenMinValue->appendPlainText(QString::number(ui.GreenMinSlider->value()));
	ui.BlueMaxValue->clear();
	ui.BlueMaxValue->appendPlainText(QString::number(ui.BlueMaxSlider->value()));
	ui.BlueMinValue->clear();
	ui.BlueMinValue->appendPlainText(QString::number(ui.BlueMinSlider->value()));
	ui.KSizeValue->clear();
	ui.KSizeValue->appendPlainText(QString::number(ui.KSizeSlider->value()));
	ui.ThresholdValue->clear();
	ui.ThresholdValue->appendPlainText(QString::number(ui.ThresholdSlider->value()));

	// Update internal values from sliders
	RMax = ui.RedMaxSlider->value();
	RMin = ui.RedMinSlider->value();
	GMax = ui.GreenMaxSlider->value();
	GMin = ui.GreenMinSlider->value();
	BMax = ui.BlueMaxSlider->value();
	BMin = ui.BlueMinSlider->value();
	KSize = ui.KSizeSlider->value();
	Threshold = ui.ThresholdSlider->value();

	// Update Gesture data and Cursor position boxes

	/*
	POINT cursorPos;
	GetCursorPos(&cursorPos);
	ui.CursorCoordValue->appendPlainText("(" + QString::number(cursorPos.x) + " , " + QString::number(cursorPos.y) + ")");

	cv::Point* gesturePos;
	ui.GestureCoordValue->appendPlainText("(" + QString::number(cursorPos.x) + " , " + QString::number(cursorPos.y) + ")");

	ui.GestureIDValue->appendPlainText(QString::number(gestureID));
	*/
}

void QtGUI::on_PauseButton_clicked()
{
	isPause = !isPause;
	if (isPause)
	{
		ui.PauseButton->setText("Paused");
	}
	else
	{
		ui.PauseButton->setText("Unpaused");
	}
}

bool QtGUI::eventFilter(QObject *object, QEvent *event)
{
	//  If any button is pressed within the RGB text boxes update RGB values and sliders
	if (((object == ui.RedMinValue) ||
		 (object == ui.RedMaxValue) ||
		 (object == ui.GreenMinValue) ||
		 (object == ui.GreenMaxValue) ||
		 (object == ui.BlueMinValue) ||
		 (object == ui.BlueMaxValue)) 
		 && event->type() == QEvent::KeyPress)
		{
		QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
		if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
			// Read the values
			RMax = ui.RedMaxValue->toPlainText().toDouble();
			RMin = ui.RedMinValue->toPlainText().toDouble();
			GMax = ui.RedMaxValue->toPlainText().toDouble();
			GMin = ui.RedMinValue->toPlainText().toDouble();
			BMax = ui.RedMaxValue->toPlainText().toDouble();
			BMin = ui.RedMinValue->toPlainText().toDouble();

			// Change Slider Values according to box input
			ui.RedMaxSlider->setValue(RMax);
			ui.RedMinSlider->setValue(RMin);
			ui.GreenMaxSlider->setValue(GMax);
			ui.GreenMinSlider->setValue(GMin);
			ui.BlueMaxSlider->setValue(BMax);
			ui.BlueMinSlider->setValue(BMin);
		}
	}
	return QMainWindow::eventFilter(object, event);
}

bool QtGUI::isPaused()
{
	return isPause;
}

int QtGUI::getRMaxValue()
{
	return RMax;
}
int QtGUI::getGMaxValue()
{
	return GMax;
}
int QtGUI::getBMaxValue()
{
	return BMax;
}
int QtGUI::getRMinValue() 
{
	return RMin;
}
int QtGUI::getGMinValue()
{
	return GMin;
}
int QtGUI::getBMinValue() 
{
	return BMin;
}
int QtGUI::getKSize()
{
	return KSize;
}
int QtGUI::getThreshold()
{
	return Threshold;
}
