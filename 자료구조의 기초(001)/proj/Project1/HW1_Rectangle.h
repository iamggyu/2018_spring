#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

using namespace std;

class Rectangle
{
public:
	Rectangle();
	Rectangle(int, int, int, int);
	~Rectangle();
	int getWidth();
	int getHeight();
	void setWidth(int);
	void setHeight(int);
	int operator==(const Rectangle&);
	int operator-(const Rectangle&);
	int operator+(const Rectangle&);
	Rectangle operator&(const Rectangle&);
	Rectangle operator|(const Rectangle&);
	friend ostream& operator<<(ostream&, const Rectangle&);
private:
	int xlow, ylow, width, height;
};

#endif