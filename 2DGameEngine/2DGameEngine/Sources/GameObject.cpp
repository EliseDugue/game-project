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
	position.x--;
}

void GameObject::goRight()
{
	position.x++;
}

void GameObject::render(/*std::function<void(bool)> drawing*/) {

	GLuint id = glGenLists(1);
	glNewList(id, GL_COMPILE_AND_EXECUTE);

	/* Code de dessin */
	
	rectangle->drawRect(true);

	glEndList();

	rectangle->setIdList(id);

}
