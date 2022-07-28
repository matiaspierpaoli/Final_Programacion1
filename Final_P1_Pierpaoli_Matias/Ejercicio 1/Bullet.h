#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

class Bullet : public Entity
{
public:
	Bullet(Position* _position, Size* _size);
	void draw(int x, int y);	
};

#endif BULLET_H
