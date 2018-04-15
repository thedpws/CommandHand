#include "MyVideo.h"

int aifaofoa() {
	return 0;
}

MyVideo::MyVideo()
{
	VideoCapture cap(0);
	this->vc = cap;
	updateFrame();
}
 bool MyVideo::updateFrame()
 {
	 if (vc.isOpened()) 
	 {
		 vc >> currentFrame;
		 return true;
	 }
	 else 
	 {
		 return false;
	 }
}

 Mat MyVideo::getFrame() {
	 return currentFrame;
}