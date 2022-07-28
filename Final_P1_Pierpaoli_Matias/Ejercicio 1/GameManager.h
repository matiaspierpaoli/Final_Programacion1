#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Ship.h"
#include "Bullet.h"
#include "Asteroid.h"
#include "HUD.h"
#include "PlayerStats.h"

class GameManager
{
private:
	static const int asteroidsAmount = 6; // Number of asteroids

	// Objects
	Entity* ship; // Player
	list<Bullet*> bullets; // Bullets
	Entity* asteroids[asteroidsAmount]; // Asteroids
	HUD hud; // HUD
	PlayerStats playerStats; // Stats such as lives, score and active asteroids
	bool exit = false; // Exit

	void drawScreen(); // Output
	void updateScreen(); // Update

public:
	GameManager(); // Constructor
	~GameManager(); // Destructor
	void gameLoop(); // Main game loop called in main()
};

#endif GAMEMANAGER_H
