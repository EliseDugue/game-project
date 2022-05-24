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
#include "SDL_image.h"
#include <math.h>
#include <functional>


class Game
{
public:
	Game(); //construtor
	~Game(); //destructor

	unsigned int getWindowWidth();
	unsigned int getWindowHeight();

	void onWindowResized(unsigned int width, unsigned int height);

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

	unsigned int WINDOW_WIDTH = 800;
	unsigned int WINDOW_HEIGHT = 600;

	int count;


};

#endif // !Game_h


