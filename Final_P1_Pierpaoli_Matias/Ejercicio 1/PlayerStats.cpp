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
	cout << "Lives: " << lives << endl;
}

void PlayerStats::drawScore(int score)
{
	goToCoordinates(getScreenWidth() - 10, 2);
	cout << "Score: " << score << endl;
}

void PlayerStats::drawActiveAsteroids()
{
	goToCoordinates(getScreenWidth() / 2 - 10, 1);
	cout << "Active Asteroids: " << activeAsteroids << endl;
}
