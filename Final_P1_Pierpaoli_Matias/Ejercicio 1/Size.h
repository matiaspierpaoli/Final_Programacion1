#ifndef SIZE_H
#define SIZE_H

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

#endif SIZE_H