#pragma once

#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#include "blur_debug.h"
#include "CommandHand.h"

int ksize = 1;

int blur_debug::runDebug()
{
	cv::VideoCapture cap(0);
	cv::namedWindow("original mat", cv::WINDOW_NORMAL);
	cv::namedWindow("binary mat", cv::WINDOW_NORMAL);
	cv::Mat frame;
	cv::Mat frame_threshold;

	cv::createTrackbar("Ksize", "binary mat", &ksize, 255, on_ksize_thresh_trackbar);

	while ((char)cv::waitKey(1) != 'q') {
		cap >> frame;
		if (frame.empty())
		{
			break;
		}
		cv::Scalar lo_gbr(CommandHand::lo_b, CommandHand::lo_g, CommandHand::lo_r);
		cv::Scalar hi_gbr(CommandHand::hi_b, CommandHand::hi_g, CommandHand::hi_r);
		inRange(frame, lo_gbr, hi_gbr, frame_threshold);
		cv::blur(frame_threshold, frame_threshold, cv::Size(ksize, ksize));
		cv::imshow("original mat", frame);
		cv::imshow("binary mat", frame_threshold);
	}
	return 0;
}

void blur_debug::on_ksize_thresh_trackbar(int, void *)
{
	cv::setTrackbarPos("Ksize", "binary mat", ksize);
}
