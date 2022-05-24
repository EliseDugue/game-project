#pragma once

#include "Headers/Game.h"

class TextureManager
{

public:
	TextureManager();
	~TextureManager();


	SDL_Surface* getSurface();
	static void setSurface(const char* new_filename);

	GLuint getTextureID();
	void setTextureID(GLuint new_textureID);

	const char* getFilename();
	void setFilename(const char* new_filename);

	static GLuint loadTexture(const char* filename, SDL_Surface *surface, GLuint textureID);
	//static GLuint loadTextureObject(TextureManager texture);
	static GLuint renderTextureIDList();
	static void applyTextureFromList(GLuint id_list);
	static void cleanTexture(SDL_Surface *surface, GLuint textureID);

private:
	const char* filename;
	static SDL_Surface *surface;
	GLuint textureID;
};


