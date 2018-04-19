#include "Gesture.h"

Gesture::Gesture()
{
	Coordinates coords;
	this->coords = coords;
	id = -1;
}
void Gesture::update() {}

Coordinates* Gesture::getCoordinates()
{
	return &coords;
}

int Gesture::getID()
{
	return id;
}

int Gesture::setID(int id)
{
	this->id = id;
}