#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

#include "Ship.h"

class PlayerStats 
{ 
private:
	int activeAsteroids;
	int objective = 10;

public:
	PlayerStats();
	~PlayerStats();
	void addActiveAsteroids();
	void substractActiveAsteroids();
	void drawLives(int lives);
	void drawScore(int score);
	void drawObjective();
	void drawActiveAsteroids();
};

#endif PLAYERSTATS_H
