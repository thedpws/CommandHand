#pragma once
//#include "Gesture.cpp"
#include "Coordinates.h"

class Gesture{
private:
	Coordinates coords;
	int id;

public:
	Gesture();
	void update();
	Coordinates* getCoordinates();
	void setCoordinates(Coordinates* coords);
	int getID();
	bool setID(int id);
};