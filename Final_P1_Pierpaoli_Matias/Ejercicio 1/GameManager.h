#pragma once
#include "Ship.h"
#include "Bullet.h"
#include "Asteroid.h"


class GameManager
{
private:
	Entity* entities[3];
	bool exit = false; // Exit

	void drawScreen();
	void updateScreen();
	
public:
	GameManager(); // Constructor
	~GameManager(); // Destructor
	void gameLoop(); // Main game loop called in main()



};
