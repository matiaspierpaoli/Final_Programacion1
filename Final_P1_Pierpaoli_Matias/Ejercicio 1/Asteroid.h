#pragma once
#include "Entity.h"

class Asteroid : public Entity
{
private:
public:
	Asteroid(Position _position, Size _size, Movement _movement);
	void draw(int x, int y);
	

};
