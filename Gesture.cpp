#include "Gesture.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

Gesture::Gesture()
{
	//default values for its center and id
	p = new cv::Point(350, 250);
	id = -1;
}

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