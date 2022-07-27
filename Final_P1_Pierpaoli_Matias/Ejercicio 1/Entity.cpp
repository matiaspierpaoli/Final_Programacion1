#include "Entity.h"

Entity::Entity(Position _position, Size _size)
{
	position = _position;
	size = _size;
}

void Entity::draw(int x, int y)
{

}

void Entity::travelUp()
{
	if (position.getY() <= 5)
		position.setY(5);
	else
		position.setY(position.getY() - 1);
}

void Entity::travelDown()
{
	if (position.getY() <= getScreenHeight() - 2)
		position.setY(2);
	else
		position.setY(position.getY() + 1);
}

void Entity::travelLeft()
{
	if (position.getX() <= 3)
		position.setX(3);
	else
		position.setX(position.getX() - 3);		
}

void Entity::travelRight()
{
	if (position.getX() + size.getX() >= getScreenWidth() - 1)
		position.setX(getScreenWidth() - 1 - size.getX());	
	else
		position.setX(position.getX() + 3);
		
}


