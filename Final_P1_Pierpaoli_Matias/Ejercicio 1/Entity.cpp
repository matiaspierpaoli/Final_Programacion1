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
	position.setY(position.getY() - 1);
}

void Entity::travelDown()
{
	position.setY(position.getY() + 1);
}

void Entity::travelLeft()
{
	position.setX(position.getX() - 1);
}

void Entity::travelRight()
{
	position.setX(position.getX() + 1);
}
