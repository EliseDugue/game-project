#include "Headers/TexGameObject.h"

TexGameObject::TexGameObject(const char* texturesheet, int w, int h)
{
	sprite->setFilename(texturesheet);
	sprite->loadTexture(texturesheet, sprite->getSurface());
	this->initRect(w, h, 1, 1, 1);
	this->renderTextureIDList();
}

TexGameObject::~TexGameObject()
{
}


GLuint TexGameObject::renderTextureIDList()
{

	RectangleQuad *rect = this->getRect();
	int x = (rect->getWidth())/2;
	int y = (rect->getHeight())/2;

	GLuint id = glGenLists(1); // 1 pour generer une liste
		// GL_COMPILE permet d’envoyer la liste de commandes au GPU
		// sans l’exécuter (contrairement à GL_COMPILE_AND_EXECUTE)

	glNewList(id, GL_COMPILE);
	/* Code de dessin */
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);

	glTexCoord2f(0, 1);
	glVertex2f(-x, -y);

	glTexCoord2f(1, 1);
	glVertex2f(x, -y);

	glTexCoord2f(1, 0);
	glVertex2f(x, y);

	glTexCoord2f(0, 0);
	glVertex2f(-x, y);

	glEnd();

	glEndList();

	sprite->setIDList(id);

	return id;

}

void TexGameObject::render() {
	//sprite = getSprite();
	
	sprite->applyTextureFromList();
}




