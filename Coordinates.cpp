#include "Coordinates.h"

Coordinates::Coordinates(int x, int y)
{
	this -> x = x;
	this -> y = y;
}

Coordinates::Coordinates()
{
	this -> x = -1;
	this -> y = -1;
}

int Coordinates::getX()
{
	return this -> x;
}

int Coordinates::getY()
{
	return y;
}

void Coordinates::setX(int x)
{
	this->x = x;
}

void Coordinates::setY(int y)
{
	this->y = y;
}