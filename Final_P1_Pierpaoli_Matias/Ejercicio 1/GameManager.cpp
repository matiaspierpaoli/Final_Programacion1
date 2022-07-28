#include "GameManager.h"

GameManager::GameManager()
{
	hud = HUD();
	playerStats = PlayerStats();
	
	ship = new Ship(3, 0, new Position(getScreenWidth() / 2 + 5, getScreenHeight() - 3), new Size(6, 3));

	for (int i = 0; i < asteroidsAmount; i++)
	{		
		asteroids[i] = new Asteroid(new Position(rand() % 71 + 3, rand() % 10 + 6), new Size(1,1));
		playerStats.addActiveAsteroids();
	}

	hideCursor();

}

GameManager::~GameManager()
{
	delete ship; // Delete player

	bullets.clear(); // Clearing the bullets list

	// Deleting every object to erase memory
	for (int i = 0; i < asteroidsAmount; i++)
		delete asteroids[i];
	
}

void GameManager::gameLoop()
{
	// Main game loop
	while (!exit) // While exit is false
	{
		updateScreen();
		drawScreen();		

		Sleep(100);
		clearScreen();
	}
}

void GameManager::drawScreen()
{
	if (!exit)
	{
		// HUD
		playerStats.drawLives(((Ship*)ship)->getCurrentLives());
		playerStats.drawScore(((Ship*)ship)->getCurrentScore());
		playerStats.drawActiveAsteroids();
		playerStats.drawObjective();
		hud.drawFrameHUD();

		// Player
		if (((Ship*)ship)->getCurrentLives() <= 0)
			((Ship*)ship)->explode();
		else
			ship->draw(ship->getPosition().getX(), ship->getPosition().getY());

		// Bullets
		for (auto it = bullets.begin(); it != bullets.end(); it++)
		{
			(*it)->draw((*it)->getPosition().getX(), (*it)->getPosition().getY());
		}

		// Asteroids
		for (int i = 0; i < asteroidsAmount; i++)
		{
			asteroids[i]->draw(asteroids[i]->getPosition().getX(), asteroids[i]->getPosition().getY());
		}
	}
}

void GameManager::updateScreen()
{
	if (!exit)
	{
		// Input
		if (_kbhit())
		{
			char tecla = _getch();			
			if (tecla == 'a' && ship->getPosition().getX() > 3) ship->travelLeft();
			if (tecla == 'd' && ship->getPosition().getX() + ship->getSize().getWidth() < getScreenWidth() - 1) ship->travelRight();
			if (tecla == 'e')
			{
				bullets.push_back(new Bullet(new Position(ship->getPosition().getX() + ship->getSize().getWidth() / 2 - 1, ship->getPosition().getY() - 1), new Size(1, 1)));
			}
		}

		// Move or respawn bullets
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

		// Move or respawn asteroids
		for (int i = 0; i < asteroidsAmount; i++)
		{
			if (asteroids[i]->outOfBounds())
			{
				asteroids[i]->respawnAsteroid();
			}
			else
				asteroids[i]->travelDown();
		}

		// Collision detection - Ship vs Asteroids
		for (int i = 0; i < asteroidsAmount; i++)
		{
			if (ship->checkCollision(ship->getPosition(), ship->getSize(), asteroids[i]->getPosition(), asteroids[i]->getSize()))
			{
				((Ship*)ship)->takeDamage();
				asteroids[i]->respawnAsteroid();
			}
		}

		// Collision detection - Bullets vs Asteroids
		for (int i = 0; i < asteroidsAmount; i++)
		{
			for (auto it = bullets.begin(); it != bullets.end();)
			{
				if ((*it)->checkCollision((*it)->getPosition(), (*it)->getSize(), asteroids[i]->getPosition(), asteroids[i]->getSize()))
				{
					delete (*it);
					it = bullets.erase(it);
					asteroids[i]->respawnAsteroid();
					((Ship*)ship)->addScore();
				}
				else it++;
			}
		}

		// Check game status
		if (((Ship*)ship)->getCurrentLives() == 0) // Lives == 0
		{
			hud.showDefeat();
			exit = true;
		}
		else if (((Ship*)ship)->getCurrentScore() == 10) // Score == objective
		{
			hud.showVictory();
			exit = true;
		}
	}
}