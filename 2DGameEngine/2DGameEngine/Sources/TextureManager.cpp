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
}

SDL_Surface* TextureManager::getSurface() {
	return surface;
}

void TextureManager::setSurface(const char* new_filename) {

	surface = IMG_Load(("./Assets/%filename.png", new_filename));

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

void TextureManager::setTextureID(GLuint new_textureID) {
	textureID = new_textureID;
}

const char* TextureManager::getFilename() {
	return filename;
}

void TextureManager::setFilename(const char* new_filename) {
	filename = new_filename;
}

GLuint TextureManager::loadTexture(const char* filename, SDL_Surface *surface, GLuint textureID) {

	TextureManager::setSurface(filename);

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);
	glBindTexture(GL_TEXTURE_2D, 0);
}

/*static GLuint loadTextureObject(TextureManager texture) {
	

	if (surface == NULL) {
		printf("\nimage non chargee\n");
	}
	else {
		printf("\nimage chargee\n");
	}

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);
	glBindTexture(GL_TEXTURE_2D, 0);
}*/

void myDrawing() {

	// code de dessin //
	
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0, 0.0);

		glVertex2f(0.5, -0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(-0.5, 0.5);
		glVertex2f(-0.5, -0.5);
		glVertex2f(0.5, -0.5);

	glEnd();
}

GLuint TextureManager::renderTextureIDList() {

	GLuint id = glGenLists(1); // 1 pour generer une liste
		// GL_COMPILE permet d’envoyer la liste de commandes au GPU
		// sans l’exécuter (contrairement à GL_COMPILE_AND_EXECUTE)

	glNewList(id, GL_COMPILE);
	/* Code de dessin */
		myDrawing();
	glEndList();

	return id;
}

void TextureManager::applyTextureFromList(GLuint id_list) {
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
	std::cout << "Textures effacees." << std::endl;
}