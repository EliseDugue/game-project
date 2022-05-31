#pragma once

#include "Game.h"
#include <functional>

class TextureManager
{

public:
	TextureManager();
	~TextureManager();


	SDL_Surface* getSurface();
	void setSurface(const char* new_filename);

	GLuint getTextureID();
	GLuint getIDList();
	void setIDList(GLuint id);

	const char* getFilename();
	void setFilename(const char* new_filename);

	GLuint loadTexture(const char* filename, SDL_Surface *surface);
	//GLuint renderTextureIDList(std::function<void()> drawing);
	void applyTextureFromList();
	void cleanTexture(SDL_Surface *surface, GLuint textureID);

private:
	const char* filename;
	SDL_Surface *surface;
	GLuint textureID;
	GLuint id_list;
};


