#pragma once
<<<<<<< HEAD
//#include "Gesture.cpp"
=======
>>>>>>> f25d1989e330feec05c957a420825881790d2ca5
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