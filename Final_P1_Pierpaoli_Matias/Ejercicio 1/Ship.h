#pragma once
#include "Entity.h"

class Ship : public Entity
{
private:
	string art;
public:
	Ship(Position position, Size size);
	void draw();

};


