#pragma once
// External Includes
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#define CVUI_IMPLEMENTATION
#include "cvui.h"
#include "Windows.h"
#define MAIN_WINDOW "Command Hand"

// Internal Includes
#include "Gesture.h"

class MyGUI 
{
public:
	MyGUI();
	void update();
	void setGestureText();

private:
	cv::Mat videoFeed;
	std::string gestureRecognized;
	int RValue;
	int GValue;
	int BValue;

};