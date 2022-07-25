#include "Ship.h"

Ship::Ship(Position _position, Size _size) : Entity(_position,  _size)
{
	ifstream inputStream;
	inputStream.open("../Ejercicio 1/Art/Spaceship.txt", ios::in);
	inputStream >> art;
	inputStream.close();

}

void Ship::draw()
{
	cout << art;
}