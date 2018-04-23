#include "Gesture.h"

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

Gesture::Gesture()
{
	p = new cv::Point(-1, -1);
	id = -1;
}

void Gesture::update() {}

//Returns the gesture's point
cv::Point* Gesture::getPoint()
{
	return p;
}

//Sets the gesture's point
void Gesture::setPoint(cv::Point* p)
{
	this->p = p;
}

//Returns the gesture's ID
int Gesture::getID()
{
	return id;
}

//Sets the gesture's ID
bool Gesture::setID(int id)
{
	this->id = id;
	return true;
}
