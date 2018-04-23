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

Gesture* GestureRecognition::process(cv::Mat &m)
{
	//roi - region of interest. this is the gesture space
	cv::Mat roi(m, cv::Range(m.rows / 2 - CommandHand::gs_height / 2, m.rows / 2 + CommandHand::gs_height / 2), cv::Range(m.cols / 2 - CommandHand::gs_width / 2, m.cols / 2 + CommandHand::gs_width / 2));

	cv::Mat src(roi);

	inRange(src, cv::Scalar(CommandHand::lo_b, CommandHand::lo_g, CommandHand::lo_r), cv::Scalar(CommandHand::hi_b, CommandHand::hi_g, CommandHand::hi_r), roi);

	cv::blur(roi, roi, cv::Size(CommandHand::ksize, CommandHand::ksize));
	cv::threshold(roi, roi, CommandHand::thresh, 255, 0);

	cv::Mat canny_output;
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	cv::Canny(roi, canny_output, 100, 200, 3);
	cv::findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

	if (contours.empty())
	{
		return new Gesture();
	}

	int i_largest_contour;
	double largest_area = -1;

	for (int i = 0; i < contours.size(); i++)
	{
		double area = cv::contourArea(contours[i]);
		if (area >= largest_area)
		{
			i_largest_contour = i;
			largest_area = area;
		}
	}

	//std::vector<cv::Point> largest_contour = contours[i_largest_contour];


	cv::Mat drawing = cv::Mat::zeros(canny_output.size(), CV_8UC3);
	cv::Scalar color = cv::Scalar(255, 255, 255);

	for (int i = 0; i < contours.size(); i++)
	{
		//DRAW THE LARGEST CONTOUR
		if (i == i_largest_contour)
		{
			cv::drawContours(drawing, contours, i, cv::Scalar(255, 0, 0), 2, 8, hierarchy, 0, cv::Point());
		}
	}

	std::vector<cv::Point> contour = contours[i_largest_contour];
	//creating the convex hull.
	std::vector<std::vector<cv::Point>> hull(1);
	convexHull(cv::Mat(contours[i_largest_contour]), hull[0], false);
	cv::drawContours(drawing, hull, 0, cv::Scalar(255, 255, 255), 1, 8, std::vector<cv::Vec4i>(), 0, cv::Point());

	//drawing green circles around each hull index
	/*
	for (int i = 0; i < hull[0].size(); i++)
	{
		cv::circle(drawing, hull[0][i], 5, cv::Scalar(0, 255, 0));
	}
	*/

	//creating clusters
	std::vector<std::vector<cv::Point>> clusters;
	double tolerance = 20;
	for (int i = 0; i < hull[0].size(); i++)
		//for each hull index...
	{
		cv::Point hull_index = hull[0][i];
		if (clusters.empty())
		{
			std::vector<cv::Point> new_cluster;
			new_cluster.push_back(hull_index);
			clusters.push_back(new_cluster);
			continue;
		}
		bool has_cluster = false;
		for (std::vector<cv::Point> cluster : clusters)
		//for each cluster...
		{
			bool belongs_in_this_cluster = true;
			for (int i = 0; i < cluster.size(); i++)
			//for each point in the cluster
			{
				cv::Point p = cluster[i];
				double dist = std::sqrt(std::pow(p.x - hull_index.x, 2) + std::pow(p.y - hull_index.y, 2));
				//std::cout << dist << std::endl;
				//double dist = cv::norm(hull_index - p);
				if (dist >= tolerance)
				{
					belongs_in_this_cluster = false;
					break;
				}
			}
			if (belongs_in_this_cluster)
			{
				//std::cout << "belongs!" << std::endl;
				cluster.push_back(hull_index);
				has_cluster = true;
			}
		}
		//if the code reaches here, it is a new cluster!
		if (has_cluster)
		{
			continue;
		}
		std::vector<cv::Point> new_cluster;
		new_cluster.push_back(hull_index);
		clusters.push_back(new_cluster);
	}

	//simplifying each cluster into one hull index
	std::vector<cv::Point> simplified_hull_indices;
	for (std::vector<cv::Point> cluster : clusters)
	{
		double x = 0;
		double y = 0;
		for (cv::Point p : cluster)
		{
			x += p.x;
			y += p.y;
		}
		x = x / cluster.size();
		y = y / cluster.size();
		simplified_hull_indices.push_back(cv::Point((int)x, (int)y));
	}

	std::cout << simplified_hull_indices.size() << std::endl;

	//drawing big green circles around each cluster
	for (int i = 0; i < simplified_hull_indices.size(); i++)
	{
		cv::circle(drawing, simplified_hull_indices[i], 10, cv::Scalar(0, 255, 0));
	}
	/* BROKEN
	//finding convexity defects
	std::vector<cv::Point> defects;
	if (simplified_hull_indices.size() > 3) {
		cv::convexityDefects(contours, simplified_hull_indices, defects);

		//drawing convexity defects
		for (int i = 0; i < defects.size(); i++)
		{
			cv::circle(drawing, defects[i], 10, cv::Scalar(0, 255, 0));
		}
	}
	*/

	//OVERWRITING THE MAT
	for (int rows = m.rows / 2 - CommandHand::gs_height / 2; rows < m.rows / 2 + CommandHand::gs_height / 2; rows++)
	{
		for (int cols = m.cols / 2 - CommandHand::gs_width / 2; cols < m.cols / 2 + CommandHand::gs_width / 2; cols++)
		{
			m.at<cv::Vec3b>(rows, cols) = drawing.at<cv::Vec3b>(rows - (m.rows / 2 - CommandHand::gs_height / 2), cols - (m.cols / 2 - CommandHand::gs_width / 2));
		}
	}

	int gID, gX, gY;
	Gesture* g = new Gesture();
	std::cout << gX << "\t" << gY << std::endl;
	g->setID(simplified_hull_indices.size() - 2);
	g->setPoint(new cv::Point(-1,-1));
	return g;

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
