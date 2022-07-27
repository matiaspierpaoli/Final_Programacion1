#include "Asteroid.h"

Asteroid::Asteroid(Position* _position, Size* _size) : Entity(_position, _size)
{

}

void Asteroid::draw(int x, int y)
{
	goToCoordinates(x,y);
	cout << (char)35 << endl;
}
