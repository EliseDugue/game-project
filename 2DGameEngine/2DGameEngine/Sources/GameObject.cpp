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
	double size = 0.3*(rectangle->getWidth());
	position.x = position.x - size;
}

void GameObject::goRight()
{
	double size = 0.3*(rectangle->getWidth());
	position.x = position.x + size;
}

void GameObject::translate(double x, double y) {
	position.x = x;
	position.y = y;
}

void GameObject::render() {

	glPushMatrix();
		glTranslated(position.x, position.y, 0);
		glColor3d(rectangle->getRedValue(), rectangle->getGreenValue(), rectangle->getBlueValue());
		glCallList(rectangle->getIdList());
	glPopMatrix();

}

Position GameObject::getPosition()
{
	return position;
}


int GameObject::checkCollisionX(GameObject *b)
// AABB - AABB collision
{
	Position pos_a = this->getPosition();
	RectangleQuad *rect_a = this->getRect();
	int x_size_a = rect_a->getWidth();

	Position pos_b = b->getPosition();
	RectangleQuad *rect_b = b->getRect();
	int x_size_b = rect_b->getWidth();

	// collision x-axis?
	bool collisionX = pos_a.x + x_size_a >= pos_b.x &&
		pos_b.x + x_size_b >= pos_a.x;

	if (collisionX) {
		std::cout << "collision axe X" << std::endl;
		if (pos_a.x > pos_b.x) {
			//std::cout << "collision bord droit, bloquer mouvement gauche" << std::endl;
			return 1;
		}
		else if (pos_a.x < pos_b.x) {
			//std::cout << "collision bord gauche, bloquer mouvement droite" << std::endl;
			return 2;
		}
	}
	else {
		return 0;
	}
}

/*
bool GameObject::checkCollisionY(GameObject *b)
// AABB - AABB collision
{
	Position pos_a = this->getPosition();
	RectangleQuad *rect_a = this->getRect();
	int y_size_a = rect_a->getHeight();

	Position pos_b = b->getPosition();
	RectangleQuad *rect_b = b->getRect();
	int y_size_b = rect_b->getHeight();

	// collision y-axis?
	bool collisionY = pos_a.y + y_size_a >= pos_b.y &&
		pos_b.y + y_size_b >= pos_a.y;

	if (collisionY) {
		std::cout << "collision axe Y" << std::endl;
	}

	return collisionY;
}*/


