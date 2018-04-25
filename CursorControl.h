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

	static std::vector<cv::Point>* history;
	static int count;

	//sets the cursor position to the point "pos" on the USER'S SCREEN
	static void setCursorPos(cv::Point pos);
	
	//maps POINT P from one set of dimensions to another set of dimensions
	static cv::Point mapPoint(double x1, double y1, double x2, double y2, cv::Point p);
	
	//performs the left-click
	static void cursorClick();

	//finishes the left-click
	static void cursorUnclick();
};
