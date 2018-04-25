#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include "Gesture.h"
#include "CommandHand.h"

//#include "GestureRecognition.cpp"
/*
	Eventually, this class will return a Gesture* data.
	Using example from 
		https://docs.opencv.org/trunk/da/d97/tutorial_threshold_inRange.html
	to create threshold

*/

class GestureRecognition
{
private:

	std::vector<std::vector<cv::Point>> gestures;
	
	//bool array so we know what gesture ID's are occupied
	bool has[10];
	
	//mins and maxs for the inrange function
	int lo_r = CommandHand::lo_r;
	
	int hi_r = CommandHand::hi_r;

	int lo_g = CommandHand::lo_g;
	
	int hi_g = CommandHand::hi_g;

	int lo_b = CommandHand::lo_b;
	
	int hi_b = CommandHand::hi_b;

	//blurring kernel size
	int ksize = CommandHand::ksize;
	
	//thresholding size
	int thresh = CommandHand::thresh;

	void inRangeProcessing(cv::Mat* m);
	
	cv::Mat binary_mask;

public:
	GestureRecognition();
	 //accessor
	cv::Mat getBinaryMask();
	
	//the main functionality of the class
	Gesture* process(cv::Mat &m);
	
	//mutators
	void setHiR(int i);
	
	void setLoR(int i);
	
	void setHiG(int i);
	
	void setLoG(int i);
	
	void setHiB(int i);
	
	void setLoB(int i);

	void setKSize(int i);
	
	void setThreshSize(int i);
};
