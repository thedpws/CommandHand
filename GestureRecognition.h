#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include "Gesture.h"

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
	//ofstream file_stream;

	std::vector<std::vector<cv::Point>> gestures;
	bool has[10];
	int lo_r;
	int hi_r;

	int lo_g;
	int hi_g;

	int lo_b;
	int hi_b;

	int ksize;
	int thresh;

	void lo_r_trackbar(int, void*);
	void hi_r_trackbar(int, void*);
	void lo_g_trackbar(int, void*);
	void hi_g_trackbar(int, void*);
	void lo_b_trackbar(int, void*);
	void hi_b_trackbar(int, void*);

	void inRangeProcessing(cv::Mat* m);

	std::vector<cv::Point> open_hand_contour;
	std::vector<cv::Point> closed_hand_contour;

public:
	GestureRecognition();
	Gesture* process(cv::Mat &m);
};
