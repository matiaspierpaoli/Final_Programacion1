#include "HUD.h"

HUD::HUD()
{
}

HUD::~HUD()
{
}

void HUD::showVictory()
{
	goToCoordinates(getScreenWidth() / 2 - 6, getScreenHeight() / 2 + 6);
	cout << "VICTORY!" << endl;
	cin.get();
}

void HUD::showDefeat()
{
	goToCoordinates(getScreenWidth() / 2 - 6, getScreenHeight() / 2);
	cout << "DEFEAT!" << endl;
	cin.get();
}

void HUD::drawFrameHUD()
{
	drawFrame(1, 5, getScreenWidth() - 1, getScreenHeight());
}
