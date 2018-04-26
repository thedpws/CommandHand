#include "Drawer.h"

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

bool Drawer::draw(cv::Mat &m, Gesture g)
{
	//draw a circle around the coordinates of the gesture.
	Scalar* red = new Scalar(0, 0, 255);
	
	//draws a red dot, indicating the gesture's lcoation.
	circle(m, *g.getPoint(), 5, *red, 5, 8, 0);

	// Creates text for Gesture ID
	// Creates text for Gesture and Cursor Coords
	int mat_size_x = m.cols;
	
	int mat_size_y = m.rows;
	
	Point text_origin;
	
	std::string text_to_print;
	
	int font_face = FONT_HERSHEY_SCRIPT_SIMPLEX;

	// Generates FPS Text
	text_to_print = std::to_string(37);
	
	int baseline = 0;
	
	Size text_size = cv::getTextSize(text_to_print, font_face, TEXT_SCALING, TEXT_THICCNESS, &baseline);
	
	text_origin.x = mat_size_x - text_size.width;
	
	text_origin.y = mat_size_y;
	/*
	putText(
		m, 
		text_to_print, 
		text_origin, 
		font_face, 
		TEXT_SCALING, 
		Scalar(
			255.f, 
			0.f, 
			0.f
		), 
		TEXT_THICCNESS, 8);
		*/

	// Generates Cursor Coordinate Text
	int sprintf_success;
	
	char cursor_coords[50];
	
	// Get position of cursor as point (from Windows.h)
	POINT cursorPos;
	GetCursorPos(&cursorPos);
	
	sprintf_success = std::sprintf(cursor_coords, "Cursor at (%d,%d)", cursorPos.x, cursorPos.y);
	
	text_size = cv::getTextSize(cursor_coords, font_face, TEXT_SCALING, TEXT_THICCNESS, &baseline);
	
	text_origin.x = mat_size_x - text_size.width;
	
	text_origin.y -= text_size.height + baseline;
	
	putText(
		m, 
		cursor_coords, 
		text_origin, 
		font_face, 
		TEXT_SCALING, 
		Scalar(
			255.f, 
			0.f, 
			0.f
		), 
		TEXT_THICCNESS, 
		8
	);

	// Generates Gesture Text
	char gesture_coords[50];
	
	sprintf_success = std::sprintf(gesture_coords, "Gesture at (%d,%d)", g.getPoint() -> x, g.getPoint() -> y);
	
	text_size = cv::getTextSize(gesture_coords, font_face, TEXT_SCALING, TEXT_THICCNESS, &baseline);
	
	text_origin.x = mat_size_x - text_size.width;
	
	text_origin.y -= text_size.height + baseline;
	
	putText(m, gesture_coords, text_origin, font_face, TEXT_SCALING, Scalar(255.f, 0.f, 0.f), TEXT_THICCNESS, 8);

	// Displays Gesture ID
	char gesture_ID_buffer[50];
	
	sprintf_success = std::sprintf(gesture_ID_buffer, "Gesture ID: %d", g.getID());
	
	text_size = cv::getTextSize(gesture_ID_buffer, font_face, TEXT_SCALING, TEXT_THICCNESS, &baseline);
	
	text_origin.x = mat_size_x - text_size.width;
	
	text_origin.y -= text_size.height + baseline;
	
	putText(m, gesture_ID_buffer, text_origin, font_face, TEXT_SCALING, Scalar(255.f, 0.f, 0.f), TEXT_THICCNESS, 8);

	// Create text for Gesture and Cursor Coords
	int MatSizeX = m.cols;
	
	int MatSizeY = m.rows;
	
	Point textOrigin;
	
	std::string TextToPrint;
	
	int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
	return true;
}