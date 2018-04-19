#pragma once
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "Gesture.h"
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>


class Drawer
{
public:
	static bool draw(cv::Mat &m, Gesture g);

};