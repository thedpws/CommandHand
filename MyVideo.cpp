#include "MyVideo.h"
#include "CommandHand.h"
#include <opencv2/imgproc.hpp>
#include <iostream>


MyVideo::MyVideo()
{
	VideoCapture vc(0);
	this->vc = vc;
	cv::Mat unflipped;
	vc >> currentFrame;

	//create the Gesture Space.
	int x_center = currentFrame.cols/2;
	int y_center = currentFrame.rows/2;
	p_high = new Point(x_center + CommandHand::gs_width / 2, y_center + CommandHand::gs_height/2);
	p_low = new Point(x_center - CommandHand::gs_width / 2, y_center - CommandHand::gs_height / 2);
	
	
}


 bool MyVideo::updateFrame()
 {
	 if (vc.isOpened()) 
	 {
		 
		 cv::Mat m;
		 vc >> m;
		 cv::flip(m, m, 1);
		 currentFrame = m;

		 //if (debug)  rectangle(currentFrame, *p_low, *p_high, *color, 5,8,0);
		 //std::cout << p_high->x << std::endl;
		 return true;
	 }
	 else 
	 {
		 return false;
	 }
}

 Mat* MyVideo::getFrame() 
 {
	 updateFrame();
	 return &currentFrame;
}
 int MyVideo::getHeight()
 {
	 return currentFrame.rows;
}
 int MyVideo::getWidth()
 {
	 return currentFrame.cols;
 }
 bool MyVideo::isOpened() 
 {
	 return vc.isOpened();
 }