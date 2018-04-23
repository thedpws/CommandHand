#include "CursorControl.h"
#include "CommandHand.h"

//Given x and y coordinates of two different sized screens, return new coordinates that maps
//and scales what the display on the first screen is showing onto the second screen
cv::Point CursorControl::mapPoint(
		double x1, double y1,
		double x2, double y2,
		cv::Point p
)
{
	//x-axis multiplier
	double kx = 4;

	//y-axis multiplier
	double ky = 10;

	//formulas for x and y
	//this code ensures a consistent ratio between the two sets of dimensions (camera dimensions and screen dimensions)
	//distance scaling is based on the CENTER of the screens
	double x = ((double)(p.x) - x1 / 2) * x2 * kx / x1 + x2 / 2;

	double y = ((double)(p.y) - y1 / 2) * y2 * ky / y1 + y2 / 2;

	//std::cout << p.x << "\t" << x << "\t\t" << p.y << "\t" << y << std::endl;
    return cv::Point((int)x, (int)y);
}

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
	if (g.getID() == 0) cursorClick();
	else cursorUnclick();
}

/*
	This code below was based on this internet post:
		https://cboard.cprogramming.com/windows-programming/101888-simulate-left-mouse-button-vk_lbutton.html
*/
void CursorControl::cursorClick()
{
	INPUT Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	::SendInput(1, &Input, sizeof(INPUT));
}

void CursorControl::cursorUnclick()
{
	INPUT Input = { 0 };
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &Input, sizeof(INPUT));

}
