#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

#include "Ship.h"

class PlayerStats 
{ 
private:
	int activeAsteroids;

public:
	PlayerStats();
	~PlayerStats();
	void addActiveAsteroids();
	void substractActiveAsteroids();
	void drawLives(int lives);
	void drawScore(int score);
	void drawActiveAsteroids();
};

#endif PLAYERSTATS_H
