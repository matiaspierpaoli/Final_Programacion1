#pragma once
#include "Header.h"
#include "Movement.h"

class Entity
{
private:
	

public:

	Entity(Position _position, Size _size, Movement _movement);

	Position position;
	Size size;
	Movement movement;

	virtual void draw(int x, int y);





};
