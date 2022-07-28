#include "PlayerStats.h"

PlayerStats::PlayerStats() 
{
	activeAsteroids = 0;
}

PlayerStats::~PlayerStats()
{
}

void PlayerStats::addActiveAsteroids()
{
	activeAsteroids++;
}

void PlayerStats::substractActiveAsteroids()
{
	activeAsteroids--;
}

void PlayerStats::drawLives(int lives)
{
	goToCoordinates(3,2);
	cout << "Lives: ";
	for (int i = 0; i < lives; i++)
	{
		goToCoordinates(10 + i, 2);
		cout << (char)3;
	}	
}

void PlayerStats::drawScore(int score)
{
	goToCoordinates(getScreenWidth() - 11, 2);
	cout << "Score: " << score << endl;
}

void PlayerStats::drawActiveAsteroids()
{
	goToCoordinates(getScreenWidth() / 2 - 10, 2);
	cout << "Active Asteroids: " << activeAsteroids << endl;
}

void PlayerStats::drawObjective()
{
	goToCoordinates(getScreenWidth() - 16, 3);
	cout << "Reach " << objective << " to win" << endl;
}
