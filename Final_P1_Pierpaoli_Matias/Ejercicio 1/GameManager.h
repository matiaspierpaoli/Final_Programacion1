#pragma once
#include "Ship.h"
#include "Bullet.h"
#include "Asteroid.h"



class GameManager
{
private:
	static const int entitiesAmount = 3;
	Entity* entities[entitiesAmount];
	bool exit = false; // Exit

	void drawScreen();
	void updateScreen();
	
public:
	GameManager(); // Constructor
	~GameManager(); // Destructor
	void gameLoop(); // Main game loop called in main()
	int getEntitiesAmount();



};
