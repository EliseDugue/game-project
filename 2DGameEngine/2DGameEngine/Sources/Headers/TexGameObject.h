#pragma once

#include "Game.h"
#include "GameObject.h"
#include "TextureManager.h"

class TexGameObject : public GameObject
{
public:
	TexGameObject(const char* texturesheet);
	~TexGameObject();

	//void init(const char* texturesheet);
	void render();

	//TextureManager* getSprite();
	TextureManager *sprite = new TextureManager;
};

