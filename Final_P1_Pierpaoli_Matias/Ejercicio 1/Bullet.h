#pragma once
#include "Entity.h"

class Bullet : public Entity
{
private:
	string art;
public:
	Bullet(Position position, Size size);
	void draw();

};
