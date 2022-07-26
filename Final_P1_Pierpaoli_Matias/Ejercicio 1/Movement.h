#pragma once

class Movement 
{
private:

public:
	Movement();
	~Movement();
	void travelUp(int y);
	void travelDown(int y);
	void travelLeft(int x);
	void travelRight(int x);
};
