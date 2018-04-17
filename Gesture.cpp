#include "Gesture.h"
#include "Coordinates.h"

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

void Gesture::setCoordinates(Coordinates* c)
{
	coords = *c;
}

int Gesture::getID()
{
	return id;
}

bool Gesture::setID(int id)
{
	this->id = id;
	return true;
}