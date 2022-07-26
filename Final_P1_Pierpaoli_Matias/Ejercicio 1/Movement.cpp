#include "Movement.h"

Movement::Movement() 
{

}

Movement::~Movement()
{
}

void Movement::travelUp(int y)
{
	y--;
}

void Movement::travelDown(int y)
{
	y++;
}

void Movement::travelLeft(int x)
{
	x--;
}

void Movement::travelRight(int x)
{
	x++;
}
