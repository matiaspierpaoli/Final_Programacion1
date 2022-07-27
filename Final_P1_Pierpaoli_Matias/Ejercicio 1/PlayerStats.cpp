#include "PlayerStats.h"

PlayerStats::PlayerStats() 
{
}

PlayerStats::~PlayerStats()
{
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
}
