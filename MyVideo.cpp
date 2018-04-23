#include "MyVideo.h"
#include "CommandHand.h"

#include <iostream>


MyVideo::MyVideo()
{
	VideoCapture vc(0);
	this->vc = vc;
	vc >> current_frame;

	//create the Gesture Space.
	int x_center = current_frame.cols/2;
	int y_center = current_frame.rows/2;
	p_high = new Point(x_center + CommandHand::gs_width / 2, y_center + CommandHand::gs_height/2);
	p_low = new Point(x_center - CommandHand::gs_width / 2, y_center - CommandHand::gs_height / 2);


}


 bool MyVideo::updateFrame()
 {
	 if (vc.isOpened())
	 {

		 vc >> current_frame;
		 //if (debug)  rectangle(current_frame, *p_low, *p_high, *color, 5,8,0);
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
	 return &current_frame;
 }

 int MyVideo::getHeight()
 {
	 return current_frame.rows;
 }

 int MyVideo::getWidth()
 {
	 return current_frame.cols;
 }

 bool MyVideo::isOpened()
 {
	 return vc.isOpened();
 }
