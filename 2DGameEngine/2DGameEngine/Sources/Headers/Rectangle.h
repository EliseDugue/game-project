#pragma once
#include "Game.h"

class RectangleQuad
{
public:
	RectangleQuad(double m_width, double m_height, double m_red, double m_green, double m_blue);
	~RectangleQuad();

	//void initRect(double m_width, double m_height, double m_red, double m_green, double m_blue);

	void drawSquare(bool filled);
	void drawRect(bool filled);

	GLuint getIdList();
	void setIdList(GLuint m_id);

	double getWidth();
	void setWidth(double new_width);

	double getHeight();
	void setHeight(double new_height);

	double getRedValue();
	double getGreenValue();
	double getBlueValue();

	void setRGBValues(double new_red, double new_green, double new_blue);

private:

	double width;
	double height;

	double red;
	double green;
	double blue;

	GLuint id_list;

};

