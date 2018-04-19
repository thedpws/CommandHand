#pragma once
#include "Gesture.cpp"
#include "Coordinates.h"

class Gesture{
private:
	Coordinates coords;
	int id;

public:
	Gesture();
	void update();
	Coordinates* getCoordinates();
	int getID();
	int setID(int id);
};