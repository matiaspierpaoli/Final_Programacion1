#pragma once
#include "Entity.h"

class Ship : public Entity
{
private:
	int lives;
	int score;

public:
	Ship(int _lives, int _score, Position _position, Size _size);
	void draw(int x, int y);
	void takeDamage();
	void shootBullets();
	void addScore();
	int getCurrentLives();
	int getCurrentScore();
	void explode();
	

};


