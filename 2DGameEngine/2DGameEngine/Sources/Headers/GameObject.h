#pragma once
#include "Headers/Game.h"
#include "Headers/TextureManager.h"

struct Position {
	int x;
	int y;
};

class GameObject
{
public:
	GameObject(const char* texturesheet);
	~GameObject();

private:
	Position position;
	TextureManager sprite;

};

