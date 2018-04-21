#include <opencv2/opencv.hpp>

#include <opencv/highgui.h>

#include <Windows.h>
#include "MyVideo.h"
#include <iostream>
#include "GestureRecognition.h"
#include "Gesture.h"
#include "Drawer.h"
#include "CommandHand.h"

#include "rgb_debug.h"
#include "blur_debug.h"
#include "thresh_debug.h"


using namespace std;
using namespace cv;


int main()
{
	if (CommandHand::debug)
	{
		if (CommandHand::rgb_d)
		{
			return rgb_debug::runDebug();
		}
		if (CommandHand::blur_d)
		{
			return blur_debug::runDebug();
		}
		if (CommandHand::thresh_d)
		{
			return thresh_debug::runDebug();
		}
	}
	else
	{
		int clk = 0;

		MyVideo mv;
		VideoCapture vc(0);
		if (!mv.isOpened()) return -1;

		namedWindow("Video");
		Mat curr;

		GestureRecognition gr;

		Gesture* currentGesture;

		while (char(waitKey(1)) != 'q' && mv.isOpened())
		{
			//clk++;

			//for showing the Mat -- eventually we will have it show on the debugging GUI
			curr = *mv.getFrame();
			currentGesture = gr.process(curr);
			if (currentGesture == NULL) continue;
			if (curr.empty()) break;
			//if (currentGesture == NULL)
			Drawer::draw(curr, *currentGesture);
			imshow("Video", curr);


		}
		return 0;
	}
	
}