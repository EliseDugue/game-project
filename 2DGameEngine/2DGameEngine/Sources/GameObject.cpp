#include "Headers/Game.h"
#include "Headers/TextureManager.h"
#include "Headers/Rectangle.h"
#include "Headers/GameObject.h"

GameObject::GameObject()
{
	position.x = 0;
	position.y = 0;
}

GameObject::~GameObject()
{
}

void GameObject::initRect(double m_width, double m_height, double m_red, double m_green, double m_blue)
{
	rectangle = new RectangleQuad(m_width, m_height, m_red, m_green, m_blue);

	GLuint id = glGenLists(1);
	glNewList(id, GL_COMPILE);

	/* Code de dessin */

	rectangle->drawRect(true);

	glEndList();

	GLuint id_rect = rectangle->getIdList();
	id_rect = id;
	rectangle->setIdList(id);
}

RectangleQuad* GameObject::getRect()
{
	return rectangle;
}

void GameObject::setRectSize(double n_width, double n_height)
{
	rectangle->setWidth(n_width);
	rectangle->setHeight(n_height);
}

void GameObject::setRectColor(double new_red, double new_green, double new_blue)
{
	rectangle->setRGBValues(new_red, new_green, new_blue);
}

void GameObject::goLeft()
{
	double size = rectangle->getWidth();
	position.x = position.x - size;
	/*
	glPushMatrix();
		glTranslated(position.x, position.y, 0);
		glColor3d(0, 0, 1);
		glCallList(rectangle->getIdList());
	glPopMatrix();
	*/
}

void GameObject::goRight()
{
	double size = rectangle->getWidth();
	position.x = position.x + size;
	/*
	glPushMatrix();
		glTranslated(position.x, position.y, 0);
		glColor3d(1,0,0);
		glCallList(rectangle->getIdList());
	glPopMatrix();
	*/
}

void GameObject::render() {

	glPushMatrix();
		glTranslated(position.x, position.y, 0);
		glColor3d(rectangle->getRedValue(), rectangle->getGreenValue(), rectangle->getBlueValue());
		glCallList(rectangle->getIdList());
	glPopMatrix();

}
