#include "Headers/Game.h"
#include "Headers/TextureManager.h"

//TODO////////////////////////////////////////////
TextureManager *playerSprite = new TextureManager;

Game::Game()
{
}

Game::~Game()
{
}

unsigned int Game::getWindowWidth() {
	return WINDOW_WIDTH;
}

unsigned int Game::getWindowHeight() {
	return WINDOW_HEIGHT;
}

void Game::onWindowResized(unsigned int width, unsigned int height) {

	/* Espace fenetre virtuelle */
	static const float GL_VIEW_SIZE = 150.;

	float aspectRatio = width / (float)height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (aspectRatio > 1)
	{
		gluOrtho2D(
			-GL_VIEW_SIZE / 2. * aspectRatio, GL_VIEW_SIZE / 2. * aspectRatio,
			-GL_VIEW_SIZE / 2., GL_VIEW_SIZE / 2.);
	}
	else
	{
		gluOrtho2D(
			-GL_VIEW_SIZE / 2., GL_VIEW_SIZE / 2.,
			-GL_VIEW_SIZE / 2. / aspectRatio, GL_VIEW_SIZE / 2. / aspectRatio);
	}
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

	onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);


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
			
			switch (e.key.keysym.sym) {
			case 100:

				break;
			default:
				break;
			}

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

	// TEXTURES //

	// pour la transparence
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, playerTextureID);

	glBegin(GL_QUADS);

	int unit = 20;

		glTexCoord2f(0, 1);
		glVertex2f(-unit, -unit);

		glTexCoord2f(1, 1);
		glVertex2f(unit, -unit);

		glTexCoord2f(1, 0);
		glVertex2f(unit, unit);

		glTexCoord2f(0, 0);
		glVertex2f(-unit, unit);

	glEnd();

	/* Echange du front et du back buffer : mise a jour de la fenetre */
	SDL_GL_SwapWindow(window);
}

void Game::clean() {

	TextureManager::cleanTexture();

	/* Liberation des ressources associees a la SDL */
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Ressources nettoyees." << std::endl;
}

bool Game::running() {
	return isRunning;
}
