#pragma once
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

#include "Gesture.h"

#include <string.h>

#include <Windows.h>

#define FONT_HERSHEY_SCRIPT_SIMPLEX 2
#define TEXT_SCALING 1
#define TEXT_THICCNESS 1


class Drawer
{
public:
	//this function draws on the mat the center of mass of the gesture and important info like gesture ID and coordinates.
	static bool draw(cv::Mat &m, Gesture g);
};