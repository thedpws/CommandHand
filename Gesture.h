#pragma once
//#include "Gesture.cpp"
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

class Gesture{
private:
	//the center of mass of the gesture
	cv::Point* p;

	//id of the gesture recognized by the program.
	int id;
public:
	//constructor
	Gesture();
	
	//accessor methods
	cv::Point* getPoint();

	int getID();

	//mutator methods
	void setPoint(cv::Point* p);
	
	bool setID(int id);
};