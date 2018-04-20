#include "CursorControl.h"

cv::Point CursorControl::mapPoint(int x1, int y1, int x2, int y2, cv::Point p)
{
  //Given x and y coordinates of two different sized screens, return new coordinates that maps
  //and scales what the display on the first screen is showing onto the second screen

    int x = (double)p.x / (double)x1 * (double)x2;
    int y = (double)p.y / (double)y1 * (double)y2;

    return cv::Point(x, y);
}
