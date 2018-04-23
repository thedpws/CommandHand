#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;


class MyVideo
{
private:
	VideoCapture vc;
	Mat current_frame;
	bool updateFrame();
	int clk = 0;


	//GESTURE SPACE
	bool debug = true;
	void drawGS();
	Point* p_high;
	Point* p_low;
	Scalar* color = new Scalar(0, 255, 0);
public:
	MyVideo();
	Mat* getFrame();
	int getHeight();
	int getWidth();
	bool isOpened();

};
