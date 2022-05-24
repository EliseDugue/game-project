#pragma once

#include "Headers/Game.h"

class TextureManager
{

public:
	TextureManager();
	~TextureManager();


	SDL_Surface* getSurface();
	void setSurface(const char* new_filename);

	GLuint getTextureID();
	//void setTextureID(GLuint new_textureID);

	const char* getFilename();
	void setFilename(const char* new_filename);

	GLuint loadTexture(const char* filename, SDL_Surface *surface);
	//GLuint loadTextureObject(TextureManager texture);
	GLuint renderTextureIDList();
	void applyTextureFromList();
	void cleanTexture(SDL_Surface *surface, GLuint textureID);

private:
	const char* filename;
	SDL_Surface *surface;
	GLuint textureID;
	GLuint id_list;
};


