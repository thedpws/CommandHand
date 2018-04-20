#pragma once

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

class CursorControl
{
public:
	int getCursorX();
	int getCursorY();
	void setCursorPos(cv::Point pos);
private:
	cv::Point mapPoint(int x1, int y1, int x2, int y2, cv::Point p);
	cv::Point cursorPos;
};
