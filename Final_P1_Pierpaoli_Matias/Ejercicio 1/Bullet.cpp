#include "Bullet.h"

Bullet::Bullet(Position _position, Size _size) : Entity(_position, _size)
{
	ifstream inputStream;
	inputStream.open("../Ejercicio 1/Art/Bullet.txt", ios::in);
	inputStream >> art;
	inputStream.close();
}

void Bullet::draw()
{
	cout << art;
}