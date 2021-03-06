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
#include <opencv2/core/utility.hpp>
#include <opencv2/imgcodecs.hpp>
#include <stdlib.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <Windows.h>
#include <iostream>
#include <opencv2/shape/shape_distance.hpp>
#include <fstream>

GestureRecognition::GestureRecognition()
{
	cv::namedWindow("Object Detection", cv::WINDOW_NORMAL);
	//Serializing the hand contours (fail!)

	//OPEN_HAND_CONTOUR = { cv::Point(256, 110), cv::Point(231, 119), cv::Point(4, 5) };
	
	//CLOSED_HAND_CONTOUR = { cv::Point(231, 119), cv::Point(231, 119), cv::Point(245, 122) };
	/*
	std::ifstream open_file("open_hand_contour.hand");
	
	std::vector<cv::Point> sample(398);
	
	open_file.read((char*) &(this->OPEN_HAND_CONTOUR), sizeof(sample));
	
	open_file.close();
	
	std::ifstream close_file("closed_hand_contour.hand");
	
	std::vector<cv::Point> sample2(186);
	
	close_file.read((char*) &(this->CLOSED_HAND_CONTOUR), sizeof(sample2));
	
	close_file.close();
	
	std::istringstream config_file(con)
	*/
	
	//initializing the gesture array
	std::vector<std::vector<cv::Point>> gestures(10);
	
	this->gestures = gestures;
	
	//initializing the boolean array of gestures saved
	for (int i = 0; i < 10; i++)
	{
		has[i] = false;
	}


}

Gesture* GestureRecognition::process(cv::Mat &m)
{
	//roi - region of interest. this is the gesture space
	cv::Mat roi(
			m, 
			cv::Range(
				m.rows / 2 - CommandHand::gs_height / 2, 
				m.rows / 2 + CommandHand::gs_height / 2
			), 
			cv::Range(
				m.cols / 2 - CommandHand::gs_width / 2, 
				m.cols / 2 + CommandHand::gs_width / 2
			)
	);

	cv::Mat src(roi);

	//inRange function creates a binary mask from a given RGB range.
	//it classifies pixels as BLACK (out of range) and WHITE (in range). Binary because only two states.
	inRange(
			src, 
			cv::Scalar(
				CommandHand::lo_b, 
				CommandHand::lo_g, 
				CommandHand::lo_r
			), 
			cv::Scalar(
				CommandHand::hi_b, 
				CommandHand::hi_g, 
				CommandHand::hi_r
			), 
			roi
	);

	//opencv normal blur function. kernel size is read from CommandHand
	//https://docs.opencv.org/3.1.0/d4/d13/tutorial_py_filtering.html
	cv::blur(roi, roi, cv::Size(CommandHand::ksize, CommandHand::ksize));

	//threshold function cleans up the binary mask.
	//https://docs.opencv.org/3.3.0/d7/d4d/tutorial_py_thresholding.html
	cv::threshold(roi, roi, CommandHand::thresh, 255, 0);

	//saving the binary mask to the object.
	cv::Mat binary_mask(roi);
	
	//preparing for contour algorithm (canny)
	cv::Mat canny_output;
	
	std::vector<std::vector<cv::Point>> contours;
	
	std::vector<cv::Vec4i> hierarchy;
	
	//performs canny algorithm on the image
	//https://docs.opencv.org/3.1.0/da/d22/tutorial_py_canny.html
	cv::Canny(roi, canny_output, 100, 200, 3);
	
	//opencv function for finding contours. A "contour" is a vector of Points in opencv.
	cv::findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

	if (contours.empty()) return new Gesture();

	//index of the largest contour. This is important because usually several contours will be found. 
	//We are only interested in the contour of the hand, which is most likely the largest contour.
	int i_largest_contour;
	
	double largest_area = -1;

	//for every contour found...
	for (int i = 0; i < contours.size(); i++)
	{
		//calculate its area
		double area = cv::contourArea(contours[i]);
		
		//if it is the largest so far...
		if (area >= largest_area)
		{
			//save its index
			i_largest_contour = i;
		
			//record its area
			largest_area = area;
		}
	}


	cv::Mat drawing = cv::Mat::zeros(canny_output.size(), CV_8UC3);
	

	cv::Scalar white = cv::Scalar(255, 255, 255);

	//Drawing the largest contour
	cv::drawContours(drawing, contours, i_largest_contour, cv::Scalar(225, 0, 0), 2, 8, hierarchy, 0, cv::Point());

	//storing the largest contour as hand_contour
	std::vector<cv::Point> hand_contour = contours[i_largest_contour];

	//saving the contours
	for (int i = '0'; i <= '9'; i++)
	{
		if (GetKeyState(i) & 0x8000)
		{
			int n = i - '0';
	
			gestures[n] = hand_contour;
			
			has[n] = true;
		}
	}


	//creating the convex hull.
	std::vector<std::vector<cv::Point>> hull(1);
	
	//convex hull algorithm finds a polygon enclosing all points.
	//https://docs.opencv.org/2.4/doc/tutorials/imgproc/shapedescriptors/hull/hull.html
	convexHull(cv::Mat(hand_contour), hull[0], false);

	//drawing the convex hull
	cv::drawContours(drawing, hull, 0, white, 1, 8, std::vector<cv::Vec4i>(), 0, cv::Point());


	//the convex hull algorithm returns many "hull indices" around each fingertip, though only 1 hull index is desired per fingertip.
	//this is fixed by grouping indices into clusters and then assigning each cluster to a new single hull index.

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
			
				//distance formula
				double dist = std::sqrt(std::pow(p.x - hull_index.x, 2) + std::pow(p.y - hull_index.y, 2));
				
				if (dist >= tolerance)
				{
					belongs_in_this_cluster = false;
				
					break;
				}
			}
			if (belongs_in_this_cluster)
			{	
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
	
	//for each cluster...
	for (std::vector<cv::Point> cluster : clusters)
	{
		double x = 0;
	
		double y = 0;
		
		//for each index in the cluster...
		for (cv::Point p : cluster)
		{
			//sum its x and y values
			x += p.x;
		
			y += p.y;
		}
		
		//divide by sample size to obtain averages
		x = x / cluster.size();
		
		y = y / cluster.size();
		
		//use the average as the new single hull index
		simplified_hull_indices.push_back(cv::Point((int)x, (int)y));
	}

	//drawing big green circles around each cluster
	for (int i = 0; i < simplified_hull_indices.size(); i++)
	{
		cv::circle(drawing, simplified_hull_indices[i], 10, cv::Scalar(0, 255, 0));
	}


	//Drawing on top of the MAT file. The dimensions of "roi" do not match those of the original "m" so some math is required.
	for (
			int rows = m.rows / 2 - CommandHand::gs_height / 2; 
			rows < m.rows / 2 + CommandHand::gs_height / 2; 
			rows++
		) //for each row in the gesture space
	{
		for (
			int cols = m.cols / 2 - CommandHand::gs_width / 2; 
			cols < m.cols / 2 + CommandHand::gs_width / 2; 
			cols++
			) //for each column in the gesture space
		{
			//overwrite the pixel from "m" with the corresponding pixel from "roi".
			m.at<cv::Vec3b>(rows, cols) = drawing.at<cv::Vec3b>(
												rows - (m.rows / 2 - CommandHand::gs_height / 2), 
												cols - (m.cols / 2 - CommandHand::gs_width / 2)
										);
		}
	}

	//object recognition
	
	//this array holds "distances" the shape is from other gestures.
	float nness[10];
	
	//Iterates through each saved gesture and stores the similarity in the array
	for (int i = 0; i < 10; i++)
	{
		if (has[i] == false)
		{
			nness[i] = 0;
	
			continue;
		}
		//openCV shape-matching function
		nness[i] = cv::matchShapes(hand_contour, gestures[i], CV_CONTOURS_MATCH_I1, 0);
		
		//debugging output
		std::cout << nness[i] << "\t";
	}
	std::cout << std::endl;
	
	//this is the gesture to be returned
	Gesture* g = new Gesture();

	int gID, gX, gY;
	gID = -1;
	
	//iterates through the array of similarity and finds the best fit
	//assigning the best-fit ID to the gesture
	float least_dist = -1;
	
	for (int i = 0; i < 10; i++)
	{
		if (!has[i]) continue;
	
		//if new closest gesture found
		if (least_dist == -1 || least_dist > nness[i])
		{
			least_dist = nness[i];
		
			gID = i;
		}
	}
	if (least_dist > 1) gID = -1;

	//using openCV Moments to find the "center of mass" of the contour
	cv::Moments mm = cv::moments(hand_contour);
	
	gX = mm.m10 / mm.m00 + m.cols / 2 - CommandHand::gs_width / 2;
	
	gY = mm.m01 / mm.m00 + m.rows / 2 - CommandHand::gs_height / 2;

	//set the gesture id
	g->setID(gID);
	
	//set the gesture center
	g->setPoint(new cv::Point(gX, gY));
	
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

void GestureRecognition::setLoR(int i)
{
	this->lo_r = i;
}
void GestureRecognition::setHiR(int i)
{
		this->hi_g = i;
}
void GestureRecognition::setLoG(int i)
{
	this->lo_g = i;
}
void GestureRecognition::setHiG(int i)
{
	this->hi_g = i;
}
void GestureRecognition::setHiB(int i)
{
	this->hi_b = i;
}
void GestureRecognition::setLoB(int i)
{
	this->lo_b = i;
}
cv::Mat GestureRecognition::getBinaryMask()
{
	return this->binary_mask;
}
void GestureRecognition::setKSize(int i)
{
	this->ksize = i;
}
void GestureRecognition::setThreshSize(int i)
{
	this->thresh = i;
}