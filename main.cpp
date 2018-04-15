#include <opencv2/opencv.hpp>

#include <opencv/highgui.h>

#include <Windows.h>
#include "MyVideo.h"
#include <iostream>


using namespace std;
using namespace cv;
int main()
{
	MyVideo mv;
	int clk = 0;

	VideoCapture vc(0);
	if (!mv.isOpened()) return -1;

	namedWindow("Video");
	Mat curr;

	while (char(waitKey(1)) != 'q' && mv.isOpened())
	{
		clk++;
		curr = *mv.getFrame();
		if (curr.empty()) break;
		imshow("Video", curr);

		
		//imshow("Video", *mv.getFrame());
		std::cout << "Showing video...\t" << clk << std::endl;
		system("cls");
	}
	return 0;
}