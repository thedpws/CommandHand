//Given x and y coordinates of two different sized screens, return new coordinates that maps
//what the display on the first screen is showing to the second screen

#include "mapping.h"

cv::Point* mapping(
	double screenX1,
	double screenY1,
	double screenX2,
	double screenY2,
	double xCoordinateToMap,
	double yCoordinateToMap
)
  {

	double x = xCoordinateToMap / screenX1 * screenX2;
	double y = yCoordinateToMap / screenY2 * screenY2;

  return new cv::Point(x, y);
}
