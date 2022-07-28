#ifndef ENTITY_H
#define ENTITY_H

#include "Header.h"
#include "Position.h"
#include "Size.h"

class Entity
{
private:
	// Properties
	Position* position;
	Size* size;

public:
	Entity(Position* _position, Size* _size);
	~Entity();

	virtual void draw(int x, int y);

	// Movement
	void travelUp();
	void travelDown();
	void travelLeft();
	void travelRight();

	Position getPosition();
	Size getSize();

	bool checkCollision(Position position1, Size size1, Position position2, Size size2); // Check if collision within two entities
	bool outOfBounds(); // Check if collision with frame

	void respawnAsteroid();
};

#endif ENTITY_H
