#include "Drawer.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

bool Drawer::draw(cv::Mat &m, Gesture g)
{
	//draw a circle around the coordinates of the gesture.
	Scalar* red = new Scalar(0, 0, 255);
	if (g.getID() == -1) return false;
	circle(m, *g.getPoint(), 5, *red, 5, 8, 0);

	// Creates text for Gesture ID
	// Create text for Gesture and Cursor Coords
	int MatSizeX = m.cols;
	int MatSizeY = m.rows;
	Point textOrigin;
	std::string TextToPrint;
	int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;

	// Generate FPS Text
	TextToPrint = std::to_string(37);
	int baseline = 0;
	Size textSize = cv::getTextSize(TextToPrint, fontFace, TEXT_SCALING, TEXT_THICCNESS, &baseline);
	textOrigin.x = MatSizeX - textSize.width;
	textOrigin.y = MatSizeY;
	putText(m, TextToPrint, textOrigin, fontFace, TEXT_SCALING, Scalar(255.f, 0.f, 0.f), TEXT_THICCNESS, 8);

	// Generate Cursor Coordinate Text
	int sprintfSuccess;
	char cursorCoords[50];
	sprintfSuccess = std::sprintf(cursorCoords, "Cursor at (%d,%d)", 50, 50);
	textSize = cv::getTextSize(cursorCoords, fontFace, TEXT_SCALING, TEXT_THICCNESS, &baseline);
	textOrigin.x = MatSizeX - textSize.width;
	textOrigin.y -= textSize.height + baseline;
	putText(m, cursorCoords, textOrigin, fontFace, TEXT_SCALING, Scalar(255.f, 0.f, 0.f), TEXT_THICCNESS, 8);

	// Generate Gesture Text
	char gestureCoords[50];
	sprintfSuccess = std::sprintf(gestureCoords, "Gesture at (%d,%d)", g.getPoint() -> x, g.getPoint() -> y);
	textSize = cv::getTextSize(gestureCoords, fontFace, TEXT_SCALING, TEXT_THICCNESS, &baseline);
	textOrigin.x = MatSizeX - textSize.width;
	textOrigin.y -= textSize.height + baseline;
	putText(m, gestureCoords, textOrigin, fontFace, TEXT_SCALING, Scalar(255.f, 0.f, 0.f), TEXT_THICCNESS, 8);

	// Display Gesture ID
	char gestureIDBuffer[50];
	sprintfSuccess = std::sprintf(gestureIDBuffer, "Gesture ID: %d", g.getID());
	textSize = cv::getTextSize(gestureIDBuffer, fontFace, TEXT_SCALING, TEXT_THICCNESS, &baseline);
	textOrigin.x = MatSizeX - textSize.width;
	textOrigin.y -= textSize.height + baseline;
	putText(m, gestureIDBuffer, textOrigin, fontFace, TEXT_SCALING, Scalar(255.f, 0.f, 0.f), TEXT_THICCNESS, 8);

	return true;

}