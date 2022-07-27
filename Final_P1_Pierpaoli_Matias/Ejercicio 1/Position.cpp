#include "Position.h"

Position::Position(int _x, int _y)
{ 
	x = _x; 
	y = _y; 
}

void Position::setX(int _x) 
{ 
	x = _x; 
}

void Position::setY(int _y) 
{
	y = _y; 
}

int Position::getX() 
{ 
	return x; 
}

int Position::getY() 
{ 
	return y; 
}