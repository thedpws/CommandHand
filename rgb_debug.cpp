

#include "rgb_debug.h"
#include "CommandHand.h"

#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

//mins and maxs for the inrange binary mask function
int min_r = CommandHand::lo_r;

int min_g = CommandHand::lo_g;

int min_b = CommandHand::lo_b;

int max_r = CommandHand::hi_r;

int max_g = CommandHand::hi_g;

int max_b = CommandHand::hi_b;

//kernel size for normal blur function
int ksize = CommandHand::ksize;

//thresh size for thresholding
int thresh = CommandHand::thresh;

//the "alternate main method" for debugging. Has sliders and visible binary mask.
int rgb_debug::runDebug()
{
	//for getting images
	cv::VideoCapture cap(0);
	
	cv::namedWindow("original mat", cv::WINDOW_NORMAL);
	
	cv::namedWindow("binary mat", cv::WINDOW_NORMAL);
	cv::namedWindow("debug", cv::WINDOW_NORMAL);
	
	cv::Mat frame;
	
	cv::Mat frame_threshold;

	//creates trackbars

	cv::createTrackbar("Min R", "debug", &min_r, 255, on_min_r_thresh_trackbar);
	
	cv::createTrackbar("Max R", "debug", &max_r, 255, on_max_r_thresh_trackbar);
	
	cv::createTrackbar("Min G", "debug", &min_g, 255, on_min_g_thresh_trackbar);
	
	cv::createTrackbar("Max G", "debug", &max_g, 255, on_max_g_thresh_trackbar);
	
	cv::createTrackbar("Min B", "debug", &min_b, 255, on_min_b_thresh_trackbar);
	
	cv::createTrackbar("Max B", "debug", &max_b, 255, on_max_b_thresh_trackbar);

	cv::createTrackbar("Ksize", "debug", &ksize, 255, on_ksize_thresh_trackbar);

	//cv::createTrackbar("Max thresh", "debug", &max_thresh, 255, on_max_thresh_thresh_trackbar);
	
	cv::createTrackbar("Thresh", "debug", &thresh, 255, on_thresh_thresh_trackbar);

	//main loop

	while ((char)cv::waitKey(1) != 'q') {
		//save the frame
		cap >> frame;
		
		if (frame.empty())
			break;
		
		//opencv inRange function
		inRange(
				frame, 
				cv::Scalar(
					min_b, 
					min_g, 
					min_r
				), 
				cv::Scalar(
					max_b, 
					max_g, 
					max_r
				), 
				frame_threshold
		);
		
		//applies the blur filter only if ksize != 0.
		//ability to disable filters allows ability to finetune each filter
		//individually
		if (ksize != 0)
		{
			cv::blur(frame_threshold, frame_threshold, cv::Size(ksize, ksize));
		}
		
		//thresholding
		if (thresh != 0)
		{
			cv::threshold(frame_threshold, frame_threshold, thresh, 255, cv::THRESH_BINARY);
		}

		cv::imshow("original mat", frame);

		cv::imshow("binary mat", frame_threshold);
	}
	return 0;
}

//many callback methods...

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


void rgb_debug::on_thresh_thresh_trackbar(int, void *)
{
	//thresh = std::min(max_thresh - 1, thresh);
	
	cv::setTrackbarPos("Thresh", "binary mat", thresh);
}


void rgb_debug::on_ksize_thresh_trackbar(int, void *)
{
	cv::setTrackbarPos("Ksize", "binary mat", ksize);
}