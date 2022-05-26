#include "Headers/Rectangle.h"
#include "Headers/Game.h"

RectangleQuad::RectangleQuad(double m_width, double m_height, double m_red, double m_green, double m_blue)
{
	width = m_width;
	height = m_height;

	red = m_red;
	green = m_green;
	blue = m_blue;
}

RectangleQuad::~RectangleQuad()
{
}

/*void RectangleQuad::initRect(double m_width, double m_height, double m_red, double m_green, double m_blue)
{
	width = m_width;
	height = m_height;

	red = m_red;
	green = m_green;
	blue = m_blue;
}*/

void RectangleQuad::drawSquare(bool filled){

	double coord = width / 2;

	if (filled)
	{
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(0.0, 0.0);
	}
	else
	{
		glBegin(GL_LINE_STRIP);
	}

	glColor3f(red, green, blue);

	glVertex2f(coord, -coord);
	glVertex2f(coord, coord);
	glVertex2f(-coord, coord);
	glVertex2f(-coord, -coord);
	glVertex2f(coord, -coord);

	glEnd();
}

void RectangleQuad::drawRect(bool filled) {

	double x_coord = width/2;
	double y_coord = height/2;

	if (filled)
	{
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(0.0, 0.0);
	}
	else
	{
		glBegin(GL_LINE_STRIP);
	}

	glColor3f(red, green, blue);

	glVertex2f(x_coord, -y_coord);
	glVertex2f(x_coord, y_coord);
	glVertex2f(-x_coord, y_coord);
	glVertex2f(-x_coord, -y_coord);
	glVertex2f(x_coord, -y_coord);

	glEnd();
}

GLuint RectangleQuad::getIdList() {
	return id_list;
}

void RectangleQuad::setIdList(GLuint m_id) {
	m_id = id_list;
}

double RectangleQuad::getWidth()
{
	return width;
}

void RectangleQuad::setWidth(double new_width)
{
	width = new_width;
}

double RectangleQuad::getHeight()
{
	return height;
}

void RectangleQuad::setHeight(double new_height)
{
	height = new_height;
}

double RectangleQuad::getRedValue()
{
	return red;
}

double RectangleQuad::getGreenValue()
{
	return green;
}

double RectangleQuad::getBlueValue()
{
	return blue;
}

void RectangleQuad::setRGBValues(double new_red, double new_green, double new_blue)
{
	red = new_red;
	blue = new_blue;
	green = new_green;
}



