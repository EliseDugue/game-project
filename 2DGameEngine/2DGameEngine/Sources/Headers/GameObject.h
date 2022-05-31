#pragma once
#include "Game.h"
#include "Rectangle.h"

struct Position {
	int x;
	int y;
};

class GameObject {
public:
	GameObject();
	~GameObject();

	void initRect(double m_width, double m_height, double m_red, double m_green, double m_blue);
	void setRectSize(double n_width, double n_height);
	void setRectColor(double new_red, double new_green, double new_blue);

	void goLeft();
	void goRight();

	void translate(double x, double y);
	void render();

	Position getPosition();
	RectangleQuad* getRect();

	int checkCollisionX(GameObject *b);
	//bool checkCollisionY(GameObject *b);

private:
	Position position;
	RectangleQuad *rectangle;

};

