#pragma once
#include "Entity.h"

class Bullet : public Entity
{
private:
public:
	Bullet(Position _position, Size _size, Movement _movement);
	void draw(int x, int y);
	

};
