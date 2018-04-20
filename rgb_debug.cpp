

#include "rgb_debug.h"
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

int min_r = rgb_debug::d_min_r;
int min_g = rgb_debug::d_min_g;
int min_b = rgb_debug::d_min_b;
int max_r = rgb_debug::d_max_r;
int max_g = rgb_debug::d_max_g;
int max_b = rgb_debug::d_max_b;

int rgb_debug::runDebug()
{
	cv::VideoCapture cap(0);
	cv::namedWindow("original mat", cv::WINDOW_NORMAL);
	cv::namedWindow("binary mat", cv::WINDOW_NORMAL);
	cv::Mat frame;
	cv::Mat frame_threshold;

	cv::createTrackbar("Min R", "binary mat", &min_r, 255, on_min_r_thresh_trackbar);
	cv::createTrackbar("Max R", "binary mat", &max_r, 255, on_max_r_thresh_trackbar);
	cv::createTrackbar("Min G", "binary mat", &min_g, 255, on_min_g_thresh_trackbar);
	cv::createTrackbar("Max G", "binary mat", &max_g, 255, on_max_g_thresh_trackbar);
	cv::createTrackbar("Min B", "binary mat", &min_b, 255, on_min_b_thresh_trackbar);
	cv::createTrackbar("Max B", "binary mat", &max_b, 255, on_max_b_thresh_trackbar);

	//TODO what is this waitKey() for???
	while ((char)cv::waitKey(1) != 'q') {
		cap >> frame;
		if (frame.empty())
			break;
		//opencv inRange function
		inRange(frame, cv::Scalar(min_b, min_g, min_r), cv::Scalar(max_b, max_g, max_r), frame_threshold);
	
		cv::imshow("original mat", frame);
		cv::imshow("binary mat", frame_threshold);
	}
	return 0;
}

void rgb_debug::on_min_r_thresh_trackbar(int, void *)
{
	min_r = std::min(max_r - 1, min_r);
	cv::setTrackbarPos("Low R", "binary mat", min_r);
}
void rgb_debug::on_max_r_thresh_trackbar(int, void *)
{
	max_r = std::max(max_r, min_r + 1);
	cv::setTrackbarPos("High R", "binary mat", max_r);
}
void rgb_debug::on_min_g_thresh_trackbar(int, void *)
{
	min_g = std::min(max_g - 1, min_g);
	cv::setTrackbarPos("Low G", "binary mat", min_g);
}
void rgb_debug::on_max_g_thresh_trackbar(int, void *)
{
	max_g = std::max(max_g, min_g + 1);
	cv::setTrackbarPos("High G", "binary mat", max_g);
}
void rgb_debug::on_min_b_thresh_trackbar(int, void *)
{
	min_b = std::min(max_b - 1, min_b);
	cv::setTrackbarPos("Low B", "binary mat", min_b);
}
void rgb_debug::on_max_b_thresh_trackbar(int, void *)
{
	max_b = std::max(max_b, min_b + 1);
	cv::setTrackbarPos("High B", "binary mat", max_b);
}