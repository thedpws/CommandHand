#include "MyVideo.h"
#include "CommandHand.h"
#include <opencv2/imgproc.hpp>
#include <iostream>


MyVideo::MyVideo()
{
	VideoCapture vc(0);

	this->vc = vc;
	
	vc >> current_frame;

	//create the Gesture Space.
	int x_center = current_frame.cols/2;
	
	int y_center = current_frame.rows/2;
	
	
}

//Updates the video frame
 bool MyVideo::updateFrame()
 {
	 if (vc.isOpened()) 
	 {
		 cv::Mat m;
		 vc >> m;
		 //flips to achieve a mirror effect
		 cv::flip(m, m, 1);
		 current_frame = m;
		 return true;
	 }
	 else 
	 {
		 return false;
	 }
}


//Returns the height of the video frame
 int MyVideo::getHeight()
 {
	 return current_frame.rows;
 }

 Mat* MyVideo::getFrame() 
 {
	 updateFrame();
	 return &current_frame;
}
 int MyVideo::getWidth()
 {
	 return current_frame.cols;
 }

//Returns if the video has been opened or not
 bool MyVideo::isOpened()
 {
	 return vc.isOpened();
 }