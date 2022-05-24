#pragma once
class TextureManager
{

public:
	TextureManager();
	~TextureManager();
	static GLUint(const char* filename, SDL_Surface *surface, GLUint textureID);


};

