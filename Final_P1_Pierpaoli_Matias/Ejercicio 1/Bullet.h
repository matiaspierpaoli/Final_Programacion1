#pragma once
#include "Entity.h"

class Bullet : public Entity
{
public:
	Bullet(Position* _position, Size* _size);
	void draw(int x, int y);	
};
