#include "Headers/Game.h"
#include "Headers/TextureManager.h"
#include "Headers/GameObject.h"
#include "Headers/TexGameObject.h"
#include "Headers/Rectangle.h"

GameObject *player;
TexGameObject *background;
GameObject *platform1;
GameObject *platform2;

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
	static const float GL_VIEW_SIZE = 200.;
	//static const float GL_VIEW_SIZE = 20000.;

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

	player = new GameObject();
	player->initRect(15, 5, 0, 1, 0);

	background = new TexGameObject("./Assets/sky.jpg", 400, 400);

	platform1 = new GameObject();
	platform1->initRect(10, 100, 0.4, 0.2, 0);
	platform1->translate(50, -7.5);

	platform2 = new GameObject();
	platform2->initRect(10, 100, 0.4, 0.2, 0);
	platform2->translate(-50, -7.5);

}

void Game::handleEvents() {

	SDL_Event e;
	SDL_PollEvent(&e);

	/* L'utilisateur ferme la fenetre : */
	if ((e.type == SDL_KEYDOWN) && (e.key.keysym.sym == SDLK_ESCAPE)){
		isRunning = false;
	}

	int dir_collision_plat1 = 0;
	int dir_collision_plat2 = 0;

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
			case SDLK_q:
				dir_collision_plat1 = player->checkCollisionX(platform1);
				dir_collision_plat2 = player->checkCollisionX(platform2);
				if (dir_collision_plat1 != 0 || dir_collision_plat2 != 0) {
					if (dir_collision_plat1 == 1 || dir_collision_plat2 == 1) {
						std::cout << "je ne peux pas aller a gauche" << std::endl;
						break;
					}
					else {
						player->goLeft();
						std::cout << "je vais a gauche" << std::endl;
						break;
					}
				}
				else {
					player->goLeft();
					std::cout << "je vais a gauche" << std::endl;
					break;
				}
				
			case SDLK_d:
				dir_collision_plat1 = player->checkCollisionX(platform1);
				dir_collision_plat2 = player->checkCollisionX(platform2);
				if (dir_collision_plat1 != 0 || dir_collision_plat2 != 0) {
					if (dir_collision_plat1 == 2 || dir_collision_plat2 == 2) {
						std::cout << "je ne peux pas aller a droite" << std::endl;
						break;
					}
					else {
						player->goRight();
						std::cout << "je vais a droite" << std::endl;
						break;
					}

				}
				else {
					player->goRight();
					std::cout << "je vais a droite" << std::endl;
					break;
				}
			default:
				break;
			}

			break;

		default:
			break;
	}
	
}

void Game::update() {
	//std::cout << count++ << std::endl;

	//player->update();
}

void Game::render() {

	background->render();
	platform1->render();
	platform2->render();
	player->render();
	

	/* Echange du front et du back buffer : mise a jour de la fenetre */
	SDL_GL_SwapWindow(window);
}

void Game::clean() {

	delete player;
	delete background;
	delete platform1;
	delete platform2;

	/* Liberation des ressources associees a la SDL */
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Ressources nettoyees." << std::endl;
}

bool Game::running() {
	return isRunning;
}
