#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>
#include <Windows.h>
#include <iostream>
#include "MyVideo.h"
#include "GestureRecognition.h"
#include "Gesture.h"
#include "Drawer.h"
#include "CommandHand.h"
#include "CursorControl.h"
#include "rgb_debug.h"
#include "QtGUI.h"
#include <QtWidgets/QApplication>

using namespace std;

using namespace cv;


int main(int argc, char *argv[])
{

	if (CommandHand::debug)
	{
		return rgb_debug::runDebug();
	}
	else
	{
		//internal clock for calculations
		int clk = 0;

		//interface for getting frames
		MyVideo mv;
		
		
		if (!mv.isOpened())
		{
			return -1;
		}

		namedWindow("Video");
		
		Mat curr;

		GestureRecognition gr;

		Gesture* current_gesture;

		while (char(waitKey(1)) != 'q' && mv.isOpened())
		{

			//clk++;
			//for showing the Mat -- eventually we will have it show on the debugging GUI
			curr = *mv.getFrame();

			//image file without processing
			Mat raw = curr.clone();

			//image file with processing
			Mat to_be_processed = raw.clone();
			/*
			gr.setLoB(w->getBMinValue());
			
			gr.setHiB(w->getBMaxValue());
			
			gr.setLoG(w->getGMinValue());
			
			gr.setHiG(w->getGMaxValue());
			
			gr.setLoR(w->getRMinValue());
			
			gr.setHiR(w->getRMaxValue());
			
			gr.setKSize(w->getKSize());
			
			gr.setThreshSize(w->getThreshold());
			*/
			
			//send the image to "GestureRecognition" and return a gesture
			current_gesture = gr.process(curr);
			
			//if recognition failed
			if (current_gesture == NULL)
			{
				continue;
			}
			if (curr.empty())
			{
				break;
			}
			
			//draw the center of mass + debug info
			Drawer::draw(curr, *current_gesture);
			
			//w->processFrameAndUpdateGUI(&raw, &curr);

			//display the video feed
			imshow("Video", curr);

			CursorControl::update(curr, *current_gesture);
			
			//Q key will stop the program
			
			if (GetKeyState('Q') & 0x8000)
			{
				return 3;
			}
			
		}
		return 0;
	}
	
}