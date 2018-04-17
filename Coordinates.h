#pragma once

class Coordinates 
{
private:
	int x;
	int y;
public:
	Coordinates();
	Coordinates(int x, int y);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
};