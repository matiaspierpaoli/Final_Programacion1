#ifndef ASTEROID_H
#define ASTEROID_H

#include "Entity.h"

class Asteroid : public Entity
{
public:
	Asteroid(Position* _position, Size* _size);
	void draw(int x, int y);
};

#endif ASTEROID_H
