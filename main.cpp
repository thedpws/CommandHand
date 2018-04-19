#include <opencv2/opencv.hpp>

#include <opencv/highgui.h>

#include <Windows.h>
#include "MyVideo.h"
#include <iostream>
<<<<<<< HEAD
#include "GestureRecognition.h"
#include "Gesture.h"
#include "Drawer.h"
#include "MyGUI.h"
=======
>>>>>>> parent of b4ce5fc... Merge branch 'master' of https://github.com/thedpws/CommandHand


using namespace std;
using namespace cv;
int main()
{

	int clk = 0;

	MyVideo mv;
	VideoCapture vc(0);
	if (!mv.isOpened()) return -1;

	namedWindow("Video");
	Mat curr;

<<<<<<< HEAD
	GestureRecognition gr;

	Gesture* currentGesture;

	// MyGUI::MyGUI();

=======
>>>>>>> parent of b4ce5fc... Merge branch 'master' of https://github.com/thedpws/CommandHand
	while (char(waitKey(1)) != 'q' && mv.isOpened())
	{
		clk++;

		//for showing the Mat -- eventually we will have it show on the debugging GUI
		curr = *mv.getFrame();
		if (curr.empty()) break;
<<<<<<< HEAD
		Drawer::draw(curr, *currentGesture);
		cv::imshow("Video", curr);
=======
		imshow("Video", curr);
		std::cout << "Showing video...\t" << clk << std::endl;
		system("cls");
>>>>>>> parent of b4ce5fc... Merge branch 'master' of https://github.com/thedpws/CommandHand


	}
	return 0;
}