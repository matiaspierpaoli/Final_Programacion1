#pragma once
#include "Header.h"

class Entity
{
private:
	

public:

	Entity(Position _position, Size _size);

	Position position;
	Size size;

	virtual void draw(int x, int y);
	void travelUp();
	void travelDown();
	void travelLeft();
	void travelRight();
	bool checkCollision(Position position1, Size size1, Position position2, Size size2);
	bool outOfBounds();
	

};
