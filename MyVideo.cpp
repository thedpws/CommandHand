#include "MyVideo.h"


MyVideo::MyVideo()
{
	VideoCapture vc(0);
	this->vc = vc;
	updateFrame();
}

 bool MyVideo::updateFrame()
 {
	 if (vc.isOpened()) 
	 {
		 currentFrame = NULL;
		 vc >> currentFrame;
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