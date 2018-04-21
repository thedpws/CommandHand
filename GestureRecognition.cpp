#include "GestureRecognition.h"
#include "Gesture.h"
#include "CommandHand.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/matx.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/core/bufferpool.hpp>
#include <opencv2/core/mat.inl.hpp>
#include <stdlib.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>

GestureRecognition::GestureRecognition()
{
	cv::namedWindow("Object Detection", cv::WINDOW_NORMAL);
}
/*
void GestureRecognition::lo_r_trackbar(int, void*)
{
	lo_r = std::min(hi_r - 1, lo_r);
	cv::setTrackbarPos("Low R", "Object Detection", lo_r);
}
void GestureRecognition::hi_r_trackbar(int, void*)
{
	hi_r = std::max(hi_r, lo_r+1);
	cv::setTrackbarPos("High R", "Object Detection", hi_r);
}
void GestureRecognition::lo_g_trackbar(int, void*)
{
	lo_g = std::min(hi_g - 1, lo_g);
	cv::setTrackbarPos("Low G", "Object Detection", lo_g);
}
void GestureRecognition::hi_g_trackbar(int, void*)
{
	hi_g = std::max(hi_g, lo_g + 1);
	cv::setTrackbarPos("High G", "Object Detection", hi_g);
}
void GestureRecognition::lo_b_trackbar(int, void*)
{
	lo_b = std::min(hi_b - 1, lo_b);
	cv::setTrackbarPos("Low B", "Object Detection", lo_b);
}
void GestureRecognition::hi_b_trackbar(int, void*)
{
	hi_b = std::max(hi_b, lo_b + 1);
	cv::setTrackbarPos("High B", "Object Detection", hi_b);
}
*/
Gesture* GestureRecognition::process(cv::Mat &m)
{
	return new Gesture();
	
}

void GestureRecognition::inRangeProcessing(cv::Mat* m)
{
	int x_center = m->cols / 2;
	int y_center = m->rows / 2;

	for (int cols = x_center - CommandHand::gs_width / 2; cols < x_center + CommandHand::gs_width / 2; cols++)
	{
		for (int rows = y_center - CommandHand::gs_height / 2; rows < y_center + CommandHand::gs_height / 2; rows++)
		{
			cv::Mat frame = *m;

			cv::Vec3b intensity = m->at<cv::Vec3b>(rows, cols);

			uchar b = intensity.val[0];
			uchar g = intensity.val[1];
			uchar r = intensity.val[2];

			if (CommandHand::lo_b <= b &&
				b <= CommandHand::hi_b &&
				CommandHand::lo_g <= g &&
				g <= CommandHand::hi_g &&
				CommandHand::lo_r <= r &&
				r <= CommandHand::hi_r
				)
			{
				intensity.val[0] = 255;
				intensity.val[1] = 255;
				intensity.val[2] = 255;
				m->at<cv::Vec3b>(rows, cols) = intensity;
			}
			else
			{
				intensity.val[0] = 0;
				intensity.val[1] = 0;
				intensity.val[2] = 0;
				m->at<cv::Vec3b>(rows, cols) = intensity;
			}


		}
	}
}