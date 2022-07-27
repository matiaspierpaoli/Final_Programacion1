#include "GameManager.h"

GameManager::GameManager()
{
	Position shipPosition;
	shipPosition.setX(getScreenWidth() / 2 + 5);
	shipPosition.setY(getScreenHeight() - 3);

	Position asteroidPosition;
	asteroidPosition.setX(-5);
	asteroidPosition.setY(-5);

	Position bulletPosition;
	bulletPosition.setX(-5);
	bulletPosition.setY(-5);
	
	Size shipSize;
	shipSize.setX(5);
	shipSize.setY(3);

	Size asteroidSize;
	asteroidSize.setX(5);
	asteroidSize.setY(2);

	Size bulletpSize;
	bulletpSize.setX(1);
	bulletpSize.setY(3);


	entities[0] = new Ship(3, 0, shipPosition, shipSize);
	entities[1] = new Bullet(asteroidPosition, asteroidSize);
	entities[2] = new Asteroid(bulletPosition, bulletpSize);

	hideCursor();

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

