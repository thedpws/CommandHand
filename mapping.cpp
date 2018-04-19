//Given x and y coordinates of two different sized screens, return new coordinates that maps
//what the display on the first screen is showing to the second screen

#include "Coordinates.h"

Coordinates* mapping(int screenX1, int screenY1, int screenX2, int screenY2,
  int xCoordinateToMap, int yCoordinateToMap)
  {

  int x = xCoordinateToMap / screenX1 * screenX2;
  int y = yCoordinateToMap / screenY1 * screenY2;

  return new Coordinates(x, y);
}
