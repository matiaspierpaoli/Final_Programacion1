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
	position.setX(position.getX() - 3);		
}

void Entity::travelRight()
{	
	position.setX(position.getX() + 3);		
}

bool Entity::checkCollision(Position position1, Size size1, Position position2, Size size2)
{
	if (position1.getX() < position2.getX() + size2.getWidth() &&
		position1.getX() + size1.getWidth() > position2.getX() &&
		position1.getY() < position2.getY() + size2.getHeight() &&
		position1.getY() + size1.getHeight() > position2.getY())
		return true;
	else
		return false;
}

bool Entity::outOfBounds()
{
	if (position.getY() <= 5)
	{		
		return true;
	}
	else if (position.getY() + size.getHeight() >= getScreenHeight())
	{		
		return true;
	}
	else if (position.getX() <= 1)
	{			
		return true;
	}
	else if (position.getX() + size.getWidth() >= getScreenWidth())
	{		
		return true;
	}
	else return false;
}


