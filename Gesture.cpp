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
	if (id < 0) 
	{
		return -1;
	}
	this->id = id;
<<<<<<< HEAD
	return true;
=======
	return 0;
>>>>>>> f25d1989e330feec05c957a420825881790d2ca5
}