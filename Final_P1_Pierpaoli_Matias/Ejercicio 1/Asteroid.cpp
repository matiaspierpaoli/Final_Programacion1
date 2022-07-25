#include "Asteroid.h"

Asteroid::Asteroid(Position _position, Size _size) : Entity(_position, _size)
{
	ifstream inputStream;
	inputStream.open("../Ejercicio 1/Art/Asteroid.txt", ios::in);
	inputStream >> art;
	inputStream.close();
}

void Asteroid::draw()
{
	cout << art;
}