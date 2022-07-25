#include "GameManager.h"

GameManager::GameManager()
{
	Position position;
	Size size;

	entities[0] = new Ship(3, 0, 0, position, size);
	entities[0] = new Bullet(position, size);
	entities[0] = new Asteroid(position, size);

}

GameManager::~GameManager()
{
	// Deleting every object to erase memory
	for (int i = 0; i < 3; i++)	
		delete entities[i];
	
}

void GameManager::gameLoop()
{
	// Main game loop
	while (!exit) // While exit or ESC is not pressed in menu
	{
		drawScreen();
		updateScreen();
	}
}

void drawScreen()
{

}

void updateScreen()
{

}

