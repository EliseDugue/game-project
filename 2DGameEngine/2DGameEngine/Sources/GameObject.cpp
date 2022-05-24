#include "Headers/Game.h"
#include "Headers/TextureManager.h"
#include "Headers/GameObject.h"

void myDrawing() { //TODO

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

GameObject::GameObject(const char* texturesheet)
{
	//TextureManager *sprite = new TextureManager;
	sprite->setFilename(texturesheet);
	sprite->loadTexture(texturesheet, sprite->getSurface());
	sprite->renderTextureIDList(myDrawing);
}

GameObject::~GameObject()
{
}

void GameObject::update() {
	//moving the object...

	position.x = 0;
	position.y = 0;

}

void GameObject::render() {
	sprite->applyTextureFromList();	
}
