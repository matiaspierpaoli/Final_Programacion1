#ifndef ENTITY_H
#define ENTITY_H

#include "Header.h"
#include "Position.h"
#include "Size.h"

class Entity
{
private:
	Position* position;
	Size* size;

public:
	Entity(Position* _position, Size* _size);
	~Entity();

	virtual void draw(int x, int y);
	void travelUp();
	void travelDown();
	void travelLeft();
	void travelRight();
	Position getPosition();
	Size getSize();
	bool checkCollision(Position position1, Size size1, Position position2, Size size2);
	bool outOfBounds();
	void respawnAsteroid();
};

#endif ENTITY_H
