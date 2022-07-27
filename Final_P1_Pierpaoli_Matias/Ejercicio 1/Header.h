#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "list"
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
	int width;
	int height;
public:
	void setWidth(int _x)
	{
		width = _x;
	}
	void setHeight(int _y)
	{
		height = _y;
	}
	int getWidth()
	{
		return width;
	}
	int getHeight()
	{
		return height;
	}
};
