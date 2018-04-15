#include <opencv2/opencv.hpp>
#include <opencv2/opencv.hpp>

#include <opencv/highgui.h>

#include <Windows.h>

using namespace std;
using namespace cv;
/*
int main() 
{
	VideoCapture cap(0);
	if (!cap.isOpened()) 
	{
		cout << "Cam could no be opened successfully" << endl;
		return -1;
	}
	namedWindow("Video");

	while (char(waitKey(1)) != 'q' && cap.isOpened()) 
	{
		Mat frame;
		cap >> frame;
		if (frame.empty()) 
		{
			cout << "Video over" << endl;
			break;
		}
		imshow("Video", frame);
		if (GetAsyncKeyState('A') & 0x8000) 
		{
			system("pause");
			return 0;
		}


	}
	return 0;
}
*/