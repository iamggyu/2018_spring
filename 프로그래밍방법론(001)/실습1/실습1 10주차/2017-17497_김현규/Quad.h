#pragma once

/* Implement: Define Quad class */
class Quad {
public:
	Quad(float x, float y);
	~Quad();

	void setPos(float x, float y);
	virtual void draw() const = 0;
	float getX() const;
	float getY() const;

protected:
	float* center_pos;
};