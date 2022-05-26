#include "Headers/TexGameObject.h"

void myDrawing() {

	// code de dessin //

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);

	glTexCoord2f(0, 1);
	glVertex2f(-40, -40);

	glTexCoord2f(1, 1);
	glVertex2f(40, -40);

	glTexCoord2f(1, 0);
	glVertex2f(40, 40);

	glTexCoord2f(0, 0);
	glVertex2f(-40, 40);

	glEnd();
}

TexGameObject::TexGameObject(const char* texturesheet)
{
	sprite->setFilename(texturesheet);
	sprite->loadTexture(texturesheet, sprite->getSurface());
	sprite->renderTextureIDList(myDrawing);
}

TexGameObject::~TexGameObject()
{
}



/*TextureManager* TexGameObject::getSprite()
{
	return sprite;
}*/

/*
void TexGameObject::init(const char* texturesheet){
	//sprite = getSprite();
	//TexGameObject::sprite = new TextureManager;
	sprite->setFilename(texturesheet);
	sprite->loadTexture(texturesheet, sprite->getSurface());
	sprite->renderTextureIDList(myDrawing);
}*/

void TexGameObject::render() {
	//sprite = getSprite();
	sprite->applyTextureFromList();
}




