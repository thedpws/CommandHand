#include "MyGUI.h"

MyGUI::MyGUI() 
{
	cvui::init(MAIN_WINDOW);

	int ScreenResX = GetSystemMetrics(SM_CXSCREEN);
	int ScreenResY = GetSystemMetrics(SM_CYSCREEN);
	cv::Mat frame = cv::Mat(cv::Size(ScreenResX, ScreenResY), CV_8UC3);

	frame = cv::Scalar(49, 52, 49);
	cvui::text(frame, 100, 100, "Hello world!");
	cvui::imshow(MAIN_WINDOW, frame);
}