#pragma once

class Size
{
private:
	int width;
	int height;
public:
	Size(int _width, int _height);
	void setWidth(int _x);
	void setHeight(int _y);
	int getWidth();
	int getHeight();
};