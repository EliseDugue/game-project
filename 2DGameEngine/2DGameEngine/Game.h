#ifndef Game_h
#define Game_h

#include <Windows.h>
#include <wingdi.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include "SDL.h"
#include <math.h>


class Game
{
public:
	Game(); //construtor
	~Game(); //destructor

	void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running();

private:
	bool isRunning;
	SDL_Window *window;
	SDL_GLContext context;

	int count;
};

#endif // !Game_h


