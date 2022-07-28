#include "Bullet.h"

Bullet::Bullet(Position* _position, Size* _size) : Entity(_position, _size)
{
	
}

void Bullet::draw(int x, int y)
{
	goToCoordinates(x, y);
	cout << (char)220 << endl; // Draw square

}



