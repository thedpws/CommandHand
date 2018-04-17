#include "GestureRecognition.h"
#include "Gesture.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

GestureRecognition::GestureRecognition()
{

}

Gesture* GestureRecognition::process(cv::Mat* m)
{
	if (m == NULL) return NULL;
	int gID, gX, gY;
	gX = m->cols / 2;
	gY = m->rows / 2;
	Gesture* g = new Gesture();
	g->setID(1);
	Coordinates* c = new Coordinates(gX, gY);
	g->setCoordinates(c);
	return g;

}