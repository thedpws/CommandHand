#include "Drawer.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


bool Drawer::draw(cv::Mat &m, Gesture g)
{
	//draw a circle around the coordinates of the gesture.
	cv::Scalar* red = new cv::Scalar(0, 0, 255);
	if (g.getID() == -1) return false;
	cv::circle(m, *g.getPoint(), 5, *red, 5, 8, 0);
	return true;

}