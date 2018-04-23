#include "CursorControl.h"
#include "CommandHand.h"

//Given x and y coordinates of two different sized screens, return new coordinates that maps
//and scales what the display on the first screen is showing onto the second screen
cv::Point CursorControl::mapPoint(double x1, double y1, double x2, double y2, cv::Point p)
{
  //Given x and y coordinates of two different sized screens, return new coordinates that maps
  //and scales what the display on the first screen is showing onto the second screen
	double kx = 4;
	double ky = 10;
	double x = ((double)(p.x) - x1 / 2) * x2 * kx / x1 + x2 / 2;
	double y = ((double)(p.y) - y1 / 2) * y2 * ky / y1 + y2 / 2;

	std::cout << p.x << "\t" << x << "\t\t" << p.y << "\t" << y << std::endl;
    return cv::Point((int)x, (int)y);
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

/*
void cursorClick()
{
	//creates a stream of inputs that is a left click on the mouse
	//it should use the current position of the mouse
	INPUT inputs[2] = {0};
	inputs[0].type = INPUT_MOUSE;
	inputs[0].mi.dwflags = MOUSEEVENTF_LEFTDOWN;
	inputs[1].type = INPUT_MOUSE;
	inputs[1].mi.dwflags = MOUSEEVENTF_LEFTUP;

	SendInput(2, INPUTS, sizeof(INPUT));
}
*/

void CursorControl::setCursorPos(cv::Point p)
{
	SetCursorPos(p.x, p.y);
}

void CursorControl::update(cv::Mat m, Gesture g)
{
	int x1 = m.cols;
	int y1 = m.rows;

	int x2 = GetSystemMetrics(SM_CXSCREEN);
	int y2 = GetSystemMetrics(SM_CYSCREEN);

	cv::Point mapped = mapPoint(x1, y1, x2, y2, *g.getPoint());
	SetCursorPos(mapped.x, mapped.y);
}
