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
	
	
	Movement movement = Movement();

	entities[0] = new Ship(3, 0, position, shipSize, movement);
	entities[1] = new Bullet(position, asteroidSize, movement);
	entities[2] = new Asteroid(position, bulletpSize, movement);

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

		Sleep(300);
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
			entities[0]->movement.travelLeft((entities[0]->position.getY()));
			break;
		case 'd':
			entities[0]->movement.travelRight((entities[0]->position.getY()));
			break;
		default:
			break;
		}
	}






	//cout << entities[0]->position.getY() << endl;
	///*entities[0]->position.setX(entities[0]->movement.travelUp(entities[0]->position.getX()));*/
	//entities[0]->movement.travelUp((entities[0]->position.getY()));
	//cout << entities[0]->position.getY() << endl;

}

