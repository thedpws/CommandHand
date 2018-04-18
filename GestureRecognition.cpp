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

}

Gesture* GestureRecognition::process(cv::Mat* m)
{
	double shortest_dist = -1;
	int shortest_x = -1;
	int shortest_y = -1;

	if (m == NULL) return NULL;

	int x_center = m->cols / 2;
	int y_center = m->rows / 2;

	for (int cols = x_center - CommandHand::gs_width/2; cols < x_center + CommandHand::gs_width/2; cols++)
	{
		for (int rows = y_center - CommandHand::gs_height/2; rows < y_center + CommandHand::gs_height/2; rows++)
		{
			cv::Vec3b intensity = m->at<cv::Vec3b>(rows, cols);

			uchar b = intensity.val[0];
			uchar g = intensity.val[1];
			uchar r = intensity.val[2];
			double curr_dist = std::sqrt(((255 - b) ^ 2) + ((255-g) ^ 2) + ((255-r) ^ 2));
			if (curr_dist < shortest_dist || shortest_dist == -1)
				{
				shortest_dist = curr_dist;
				shortest_x = cols;
				shortest_y = rows;
				}
		}
	}
	int gID, gX, gY;
	gX = shortest_x;
	gY = shortest_y;
	Gesture* g = new Gesture();
	std::cout << gX << "\t" << gY << std::endl;
	g->setID(1);
	cv::Point* p = new cv::Point(gX, gY);
	g->setPoint(p);
	return g;

}