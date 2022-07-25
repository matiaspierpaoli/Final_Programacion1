#pragma once
#include "Entity.h"

class Asteroid : public Entity
{
private:
	string art;
public:
	Asteroid(Position position, Size size);
	void draw();

};
