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
	static void setCursor(cv::Mat videoFeed, cv::Point pos);
	static void moveCursor(cv::Mat videoFeed, Gesture g);
	static cv::Point mapPoint(int x1, int y1, int x2, int y2, cv::Point p);
	static void cursorClick(cv::point cursorPos);
private:
	cv::Point cursorPos;
};
