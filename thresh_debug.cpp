#pragma once

#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "thresh_debug.h"
#include "CommandHand.h"

int thresh = 5;
int max_thresh = 5;

int thresh_debug::runDebug()
{
	cv::VideoCapture cap(0);
	cv::namedWindow("original mat", cv::WINDOW_NORMAL);
	cv::namedWindow("binary mat", cv::WINDOW_NORMAL);
	cv::Mat frame;
	cv::Mat frame_threshold;

	cv::createTrackbar("Max thresh", "binary mat", &max_thresh, 255, on_max_thresh_thresh_trackbar);
	cv::createTrackbar("Thresh", "binary mat", &thresh, 255, on_thresh_thresh_trackbar);
	while ((char)cv::waitKey(1) != 'q') {
		cap >> frame;
		if (frame.empty())
			break;
		cv::Scalar lo_gbr(CommandHand::lo_b, CommandHand::lo_g, CommandHand::lo_r);
		cv::Scalar hi_gbr(CommandHand::hi_b, CommandHand::hi_g, CommandHand::hi_r);
		inRange(frame, lo_gbr, hi_gbr, frame_threshold);
		cv::blur(frame_threshold, frame_threshold, cv::Size(CommandHand::ksize, CommandHand::ksize));
		cv::threshold(frame_threshold, frame_threshold, thresh, max_thresh, cv::THRESH_BINARY);

		cv::imshow("original mat", frame);
		cv::imshow("binary mat", frame_threshold);
	}
	return 0;
}

void thresh_debug::on_thresh_thresh_trackbar(int, void *)
{
	//thresh = std::min(max_thresh - 1, thresh);
	cv::setTrackbarPos("Thresh", "binary mat", thresh);
}
void thresh_debug::on_max_thresh_thresh_trackbar(int, void *)
{
	//max_thresh = std::max(max_thresh, thresh+1);
	cv::setTrackbarPos("Max thresh", "binary mat", max_thresh);
}
