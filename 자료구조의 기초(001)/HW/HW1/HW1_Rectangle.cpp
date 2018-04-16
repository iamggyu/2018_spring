#include "HW1_Rectangle.h"

Rectangle::Rectangle() {
	xlow = 0;
	ylow = 0;
	width = 0;
	height = 0;
}

Rectangle::Rectangle(int x, int y, int w, int h) {
	xlow = x;
	ylow = y;
	width = w;
	height = h;
}

Rectangle::~Rectangle() {}

int Rectangle::getWidth() {
	return width;
}

int Rectangle::getHeight() {
	return height;
}

void Rectangle::setWidth(int w) {
	width = w;
}

void Rectangle::setHeight(int h) {
	height = h;
}

int Rectangle::operator==(const Rectangle &s)
{
	if (this == &s) return true;
	if ((xlow == s.xlow) && (ylow == s.ylow) && (width == s.width) && (height == s.height))
		return true;
	else
		return false;
}

ostream& operator<< (ostream& os, const Rectangle& r) {
	os << "(" << r.xlow << "," << r.ylow << ")" << endl;
	os << "Area : " << r.width*r.height << endl;
	return os;
}