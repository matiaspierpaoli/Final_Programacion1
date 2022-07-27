#include "GameManager.h"

GameManager::GameManager()
{
	Position position;
	position.setX(20);
	position.setY(10);
	
	Size shipSize;
	shipSize.setX(13);
	shipSize.setY(9);

	Size asteroidSize;
	asteroidSize.setX(5);
	asteroidSize.setY(2);

	Size bulletpSize;
	bulletpSize.setX(1);
	bulletpSize.setY(3);


	entities[0] = new Ship(3, 0, position, shipSize);
	entities[1] = new Bullet(position, asteroidSize);
	entities[2] = new Asteroid(position, bulletpSize);

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
		updateScreen();
		drawScreen();		

		Sleep(100);
		clearScreen();
	}
}

int GameManager::getEntitiesAmount()
{
	return entitiesAmount;
}

void GameManager::drawScreen()
{
	/*for (int i = 0; i < getEntitiesAmount(); i++)
	{
		entities[i]->draw(entities[i]->position.getX(), entities[i]->position.getY());
	}*/

	
	drawFrame(1, 5, getScreenWidth() - 1, getScreenHeight());

	entities[0]->draw(entities[0]->position.getX(), entities[0]->position.getY());

	
}

void GameManager::updateScreen()
{
	if(_kbhit())
	{
		char tecla = _getch();
		switch (tecla)
		{
		case 'a':
			entities[0]->travelLeft();
			break;
		case 'd':
			entities[0]->travelRight();
			break;
		default:
			break;
		}
	}



}

