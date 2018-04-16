#include "HW1_Rectangle.h"
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)>(y)?(y):(x))

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

int Rectangle::operator-(const Rectangle &s) {
	int inter_x, inter_y;
	inter_x = min(this->xlow + this->width, s.xlow + s.width) - max(this->xlow, s.xlow);
	inter_y = min(this->ylow + this->height, s.ylow + s.height) - max(this->ylow, s.ylow);
	inter_x = max(0, inter_x);
	inter_y = max(0, inter_y);
	return this->width * this->height - inter_x * inter_y;
}

int Rectangle::operator+(const Rectangle &s) {
	int inter_x, inter_y;
	inter_x = min(this->xlow + this->width, s.xlow + s.width) - max(this->xlow, s.xlow);
	inter_y = min(this->ylow + this->height, s.ylow + s.height) - max(this->ylow, s.ylow);
	inter_x = max(0, inter_x);
	inter_y = max(0, inter_y);
	return this->width * this->height + s.width * s.height - inter_x * inter_y;
}

Rectangle Rectangle::operator&(const Rectangle &s) {
	Rectangle res;
	res.xlow = min(this->xlow, s.xlow);
	res.ylow = min(this->ylow, s.ylow);
	res.width = max(this->xlow + this->width, s.xlow + s.width) - res.xlow;
	res.height = max(this->ylow + this->height, s.ylow + s.height) - res.ylow;
	return res;
}

Rectangle Rectangle::operator|(const Rectangle &s) {
	Rectangle res;
	int inter_x, inter_y;
	inter_x = min(this->xlow + this->width, s.xlow + s.width) - max(this->xlow, s.xlow);
	inter_y = min(this->ylow + this->height, s.ylow + s.height) - max(this->ylow, s.ylow);
	inter_x = max(0, inter_x);
	inter_y = max(0, inter_y);

	if (inter_x == 0 || inter_y == 0) {
		res.xlow = 0;
		res.ylow = 0;
		res.width = 0;
		res.height = 0;
		return res;
	}
	
	res.xlow = max(this->xlow, s.xlow);
	res.ylow = max(this->ylow, s.ylow);
	res.width = inter_x;
	res.height = inter_y;
	return res;
}