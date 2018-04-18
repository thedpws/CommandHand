#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "Gesture.h"

//#include "GestureRecognition.cpp"
/*
	Eventually, this class will return a Gesture* data.

*/
class GestureRecognition
{
//private:

public:
	GestureRecognition();
	Gesture* process(cv::Mat* m);
};
