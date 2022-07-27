#pragma once

class Position
{
private:
	int x;
	int y;
public:
	Position(int _x, int _y);
	void setX(int _x);
	void setY(int _y);
	int getX();
	int getY();
};
