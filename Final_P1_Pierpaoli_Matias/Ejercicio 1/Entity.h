#pragma once
#include "Header.h"


class Entity
{
private:
	Position position;
	Size size;

public:
	Entity(Position position, Size size);
	virtual void draw();





};
