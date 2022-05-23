#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen){

	/* Initialisation de la SDL */

	Uint32 flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;

	if (fullscreen) {
		flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN;
	}
	/*
	if (SDL_Init(SDL_INIT_EVERYTHING >= 0)) {
		std::cout << "Initialisation de la SDL..." << std::endl;
	}
	else {
		isRunning = false;
		const char* error = SDL_GetError();
		std::cout << "Erreur lors de l'initialisation de la SDL : " << error << std::endl;
	}*/

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		isRunning = false;
		const char* error = SDL_GetError();
		std::cout << "Erreur lors de l'initialisation de la SDL : " << error << std::endl;
	}
	else
	{
		std::cout << "Initialisation de la SDL..." << std::endl;
	}

	window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

	if (NULL != window) {
		std::cout << "Fenetre creee !" << std::endl;
	} 
	else {
		isRunning = false;
		const char* error = SDL_GetError();
		std::cout << "Erreur lors de la creation de la fenetre : " << error << std::endl;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	context = SDL_GL_CreateContext(window);

	if (NULL != context) {
		std::cout << "Contexte OpenGL cree !" << std::endl;
		isRunning = true;
	} 
	else {
		isRunning = false;
		const char* error = SDL_GetError();
		std::cout << "Erreur lors de la creation du contexte OpenGL : " << error << std::endl;
	}

}

void Game::handleEvents() {

	SDL_Event e;
	SDL_PollEvent(&e);

	/* L'utilisateur ferme la fenetre : */
	if (e.type == SDL_KEYDOWN
		&& (e.key.keysym.sym == SDLK_q || e.key.keysym.sym == SDLK_ESCAPE))
	{
		isRunning = false;
	}

	switch (e.type) {

		case SDL_QUIT:
			isRunning = false;
			break;

			/* Clic souris */
		case SDL_MOUSEBUTTONUP:
			std::cout << "Clic en x : " << e.button.x << ", y : " << e.button.y << std::endl;
			break;

			/* Touche clavier */
		case SDL_KEYDOWN:
			std::cout << "touche pressee : code = " << e.key.keysym.sym << std::endl;
			break;

		default:
			break;
	}
	
}

void Game::update() {
	std::cout << count++ << std::endl;
}

void Game::render() {
	
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBegin(GL_LINES);

		glColor3f(1., 0., 0.);
		glVertex2f(0.0, 0.0);
		glVertex2f(1.0, 0.0);

		glColor3f(0., 1., 0.);
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 1.0);

	glEnd();

	/* Echange du front et du back buffer : mise a jour de la fenetre */
	SDL_GL_SwapWindow(window);
}

void Game::clean() {
	/* Liberation des ressources associees a la SDL */
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Ressources nettoyees." << std::endl;
}

bool Game::running() {
	return isRunning;
}
