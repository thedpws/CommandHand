#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "cvui.h"
#include "Gesture.h"

class MyGUI 
{
public:
	void GUI();

private:
	cv::Mat videofeed;
};