#pragma once

#include "Game.h"
#include "GameObject.h"
#include "TextureManager.h"

class TexGameObject : public GameObject
{
public:
	TexGameObject(const char* texturesheet,int w, int h);
	~TexGameObject();

	GLuint renderTextureIDList();
	void render();
	TextureManager *sprite = new TextureManager;
};

