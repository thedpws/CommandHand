#pragma once

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "Gesture.h"
#include "Windows.h"

class CursorControl
{
public:
	int getCursorX();
	int getCursorY();
	static void update(cv::Mat video_feed, Gesture g);
private:
	static void setCursorPos(cv::Point pos);
	static cv::Point mapPoint(double x1, double y1, double x2, double y2, cv::Point p);
	static void cursorClick();
};
