#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "AwesomeLibrary.h"


using namespace std;

class Position
{
private:
	int x;
	int y;
public:
	void setX(int _x)
	{
		x = _x;
	}
	void setY(int _y)
	{
		y = _y;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}

};

class Size
{
private:
	int x;
	int y;
public:
	void setX(int _x)
	{
		x = _x;
	}
	void setY(int _y)
	{
		y = _y;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
};
