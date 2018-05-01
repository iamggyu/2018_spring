#pragma once

class Shape {
public:
	void setColor(float r, float g, float b);
	void setPos(float x, float y);
	virtual void draw() const = 0;

	float getX() const;
	float getY() const;

protected:
	float color[3];
	float pos[2];
};