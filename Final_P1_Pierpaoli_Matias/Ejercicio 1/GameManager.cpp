#include "GameManager.h"

GameManager::GameManager()
{
	Position shipPosition;
	shipPosition.setX(getScreenWidth() / 2 + 5);
	shipPosition.setY(getScreenHeight() - 4);

	Position asteroidPosition;
	asteroidPosition.setX(rand() % 71 + 3);
	asteroidPosition.setY(6);

	bulletSize.setHeight(1);
	bulletSize.setWidth(1);
	
	Size shipSize;
	shipSize.setWidth(6);
	shipSize.setHeight(3);

	Size asteroidSize;
	asteroidSize.setWidth(1);
	asteroidSize.setHeight(1);

	Size bulletpSize;
	bulletpSize.setWidth(1);
	bulletpSize.setHeight(3);

	hud = HUD();
	playerStats = PlayerStats();

	ship = new Ship(3, 0, shipPosition, shipSize);

	for (int i = 0; i < asteroidsAmount; i++)
	{
		asteroidPosition.setX(rand() % 71 + 3);
		asteroids[i] = new Asteroid(asteroidPosition, asteroidSize);	
	}

	hideCursor();

}

GameManager::~GameManager()
{
	delete ship;

	bullets.clear();

	// Deleting every object to erase memory
	for (int i = 0; i < asteroidsAmount; i++)
		delete asteroids[i];
	
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

void GameManager::drawScreen()
{
	playerStats.drawLives(((Ship*)ship)->getCurrentLives());
	playerStats.drawScore(((Ship*)ship)->getCurrentScore());
	playerStats.drawActiveAsteroids();

	drawFrame(1, 5, getScreenWidth() - 1, getScreenHeight());

	if (((Ship*)ship)->getCurrentLives() <= 0)
		((Ship*)ship)->explode();
	else	
		ship->draw(ship->position.getX(), ship->position.getY());
	
	for (auto it = bullets.begin(); it != bullets.end(); it ++)
	{		
		(*it)->draw((*it)->position.getX(), (*it)->position.getY());
	}

	for (int i = 0; i < asteroidsAmount; i++)
	{
		asteroids[i]->draw(asteroids[i]->position.getX(), asteroids[i]->position.getY());	
	}	
}

void GameManager::updateScreen()
{
	if(_kbhit())
	{
		char tecla = _getch();

		if (tecla == 'a' && ship->position.getX() > 3) ship->travelLeft();		
		if (tecla == 'd' && ship->position.getX() + ship->size.getWidth() < getScreenWidth() - 1) ship->travelRight();
		if (tecla == 'e')
		{
			bulletPosition.setX(ship->position.getX() + ship->size.getWidth() / 2 - 1);
			bulletPosition.setY(ship->position.getY() - 1);
			bullets.push_back(new Bullet(bulletPosition, bulletSize));
		}		
	}
	
	for (auto it = bullets.begin(); it != bullets.end();)
	{
		(*it)->travelUp();
		if ((*it)->outOfBounds())
		{
			delete (*it);
			it = bullets.erase(it);
		}
		else it++;
	}

	for (int i = 0; i < asteroidsAmount; i++)
	{
		if (asteroids[i]->outOfBounds())
			((Asteroid*)asteroids[i])->respawn();
		else
			asteroids[i]->travelDown();
	}

	// Collision detection
	for (int i = 0; i < asteroidsAmount; i++)
	{
		if (ship->checkCollision(ship->position, ship->size, asteroids[i]->position, asteroids[i]->size))
		{
			((Ship*)ship)->takeDamage();
			((Asteroid*)asteroids[i])->respawn();
		}
	}

	if (((Ship*)ship)->getCurrentLives() == 0)
		exit = true;		
	


}

