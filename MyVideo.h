#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;


class MyVideo 
{
private:
	VideoCapture vc;
	Mat currentFrame;

	bool updateFrame();
public:
	MyVideo();
	Mat getFrame();
};



