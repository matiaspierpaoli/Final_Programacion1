#include "Size.h"

Size::Size(int _width, int _height) 
{ 
	width = _width; 
	height = _height; 
}
void Size::setWidth(int _x) 
{ 
	width = _x; 
}

void Size::setHeight(int _y) 
{ 
	height = _y; 
}

int Size::getWidth() 
{ 
	return width; 
}

int Size::getHeight() 
{ 
	return height; 
}