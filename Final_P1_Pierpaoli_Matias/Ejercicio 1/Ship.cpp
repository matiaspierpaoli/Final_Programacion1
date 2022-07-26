#include "Ship.h"

Ship::Ship(int _lives, int _score, Position _position, Size _size, Movement _movement) : Entity(_position,  _size, _movement)
{
	lives = _lives;
	score = _score;

}

void Ship::draw(int x, int y)
{
	goToCoordinates(x, y);
	cout << "  " << (char)30;
	goToCoordinates(x, y + 1);
	cout << " " << (char)40 << (char)206 << (char)41;
	goToCoordinates(x, y + 2);
	cout << (char)30 << (char)190 << " " << (char)200 << (char)30;
}

void Ship::takeDamage()
{
}

void Ship::shootBullets()
{
}

void Ship::addScore()
{
}
