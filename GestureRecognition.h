#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "Gesture.h"

<<<<<<< HEAD
//#include "GestureRecognition.cpp"
/*
	Eventually, this class will return a Gesture* data.
=======
>>>>>>> f25d1989e330feec05c957a420825881790d2ca5

*/
class GestureRecognition
{
//private:

public:
	GestureRecognition();
	Gesture* process(cv::Mat* m);
};
