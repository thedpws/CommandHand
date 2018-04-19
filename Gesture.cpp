#include "Gesture.h"
#include "Coordinates.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

Gesture::Gesture()
{
	p = new cv::Point(-1, -1);
	id = -1;
}
void Gesture::update() {}

cv::Point* Gesture::getPoint()
{
	return p;
}

void Gesture::setPoint(cv::Point* p)
{
	this->p = p;
}

int Gesture::getID()
{
	return id;
}

bool Gesture::setID(int id)
{
	this->id = id;
	return true;
}