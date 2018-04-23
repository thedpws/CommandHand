#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;


class MyVideo 
{
private:
	
	VideoCapture vc;
	
	//for storing the current frame
	Mat current_frame;
	
	//looping function
	bool updateFrame();
	
	int clk = 0;


	//GESTURE SPACE
	bool debug = true;
	
	void drawGS();
	
	//lower right corner of gesture space
	Point* p_high;
	
	//upper left corner of gesture space
	Point* p_low;
	

	Scalar* color = new Scalar(0, 255, 0);

public:
	
	MyVideo();
	
	//returns current frame
	Mat* getFrame();
	
	//returns height of the frame
	int getHeight();
	
	//returns width of the frame
	int getWidth();
	
	bool isOpened();

};