#pragma once
#include "Ship.h"
#include "Bullet.h"
#include "Asteroid.h"
#include "HUD.h"
#include "PlayerStats.h"

class GameManager
{
private:
	static const int asteroidsAmount = 4;
	
	Entity* ship;
	list<Bullet*> bullets;
	Entity* asteroids[asteroidsAmount];
	HUD hud;
	PlayerStats playerStats;
	bool exit = false; // Exit

	void drawScreen();
	void updateScreen();
	
public:
	GameManager(); // Constructor
	~GameManager(); // Destructor
	void gameLoop(); // Main game loop called in main()
};
