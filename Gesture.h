#pragma once
//#include "Gesture.cpp"
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

class Gesture{
private:
	cv::Point* p;
	int id;
public:
	Gesture();
	void update();
	cv::Point* getPoint();
	void setPoint(cv::Point* p);
	int getID();
	bool setID(int id);
};