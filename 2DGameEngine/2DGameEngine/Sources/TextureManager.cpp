#include "Headers/TextureManager.h"
#include "Headers/Game.h"

TextureManager::TextureManager()
{
	filename = "";
	surface = NULL;
	textureID = NULL;
}

TextureManager::~TextureManager()
{
	TextureManager::cleanTexture(surface,textureID);
}

SDL_Surface* TextureManager::getSurface() {
	return surface;
}

void TextureManager::setSurface(const char* new_filename) {

	surface = IMG_Load(new_filename);
	//surface = IMG_Load("./Assets/player.png");
	if (surface == NULL) {
		printf("\nimage non chargee\n");
	}
	else {
		printf("\nimage chargee\n");
	}
}

GLuint TextureManager::getTextureID() {
	return textureID;
}

/*
void TextureManager::setTextureID(GLuint new_textureID) {
	textureID = new_textureID;
}
*/

const char* TextureManager::getFilename() {
	return filename;
}

void TextureManager::setFilename(const char* new_filename) {
	filename = new_filename;
}

GLuint TextureManager::loadTexture(const char* filename, SDL_Surface *surface) {

	setSurface(filename);
	surface = getSurface();
	//this->setSurface(filename);
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);
	glBindTexture(GL_TEXTURE_2D, 0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);

	return textureID;
}

GLuint TextureManager::renderTextureIDList(std::function<void()> drawing) {

	GLuint id = glGenLists(1); // 1 pour generer une liste
		// GL_COMPILE permet d’envoyer la liste de commandes au GPU
		// sans l’exécuter (contrairement à GL_COMPILE_AND_EXECUTE)

	glNewList(id, GL_COMPILE);
	/* Code de dessin */
		drawing();

		/*glBegin(GL_QUADS);
		glColor3f(1, 1, 1);

		glTexCoord2f(0, 1);
		glVertex2f(-40, -40);

		glTexCoord2f(1, 1);
		glVertex2f(40, -40);

		glTexCoord2f(1, 0);
		glVertex2f(40, 40);

		glTexCoord2f(0, 0);
		glVertex2f(-40, 40);

		glEnd();*/

	glEndList();

	id_list = id;

	return id;
}

void TextureManager::applyTextureFromList() {

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glCallList(id_list);
}

void TextureManager::cleanTexture(SDL_Surface *surface, GLuint textureID) {

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	SDL_FreeSurface(surface);
	glDeleteTextures(1, &textureID);
	std::cout << "Texture effacee." << std::endl;
}