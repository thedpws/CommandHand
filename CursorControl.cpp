#include "CursorControl.h"

cv::Point CursorControl::mapPoint(int x1, int y1, int x2, int y2, cv::Point p)
{
  //Given x and y coordinates of two different sized screens, return new coordinates that maps
  //and scales what the display on the first screen is showing onto the second screen

    int x = (double)p.x / (double)x1 * (double)x2;
    int y = (double)p.y / (double)y1 * (double)y2;

    return cv::Point(x, y);
}

/*
void moveCursor(cv::Mat videoFeed, Gesture g)
{
	cv::Size matSize = videoFeed.size();
	cv::Point screenPos = CursorControl::mapPoint(
		matSize.width, 
		matSize.height,
		GetSystemMetrics(SM_CXSCREEN), 
		GetSystemMetrics(SM_CYSCREEN), 
		*g.getPoint()
	);
	
	SetCursorPos(screenPos.x, screenPos.y);
}
*/

void cursorClick()
{
	//creates a stream of inputs that is a left click on the mouse
	//it should use the current position of the mouse
	INPUT inputs[2] = {0};
	inputs[0].type = INPUT_MOUSE;
	inputs[0].mi.dwflags = MOUSEEVENTF_LEFTDOWN;
	inputs[1].type = INPUT_MOUSE;
	inputs[1].mi.dwflags = MOUSEEVENTF_LEFTUP;
	
	SendInput(2, INPUTS, sizeof(INPUT);
}
