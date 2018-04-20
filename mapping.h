#pragma once

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

cv::Point* mapping(
	int screenX1,
	int screenY1,
	int screenX2,
	int screenY2,
	int xCoordinateToMap,
	int yCoordinateToMap
);