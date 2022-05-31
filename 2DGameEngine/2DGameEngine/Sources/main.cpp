#include "Headers/Game.h"
#include "Headers/TexGameObject.h"
#pragma comment(lib, "Winmm.lib")
#include <mmsystem.h>

Game *game = nullptr;

int main(int argc, char** argv)
{

	const int FPS = 60;
	const int frame_delay = 1000 / FPS;

	Uint32 frame_start;
	int frame_time;

	/* boucle principale */
	game = new Game();

	game->init("Nom du jeu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, game->getWindowWidth(), game->getWindowHeight(), false);

	PlaySound(TEXT("./Assets/Obstacle_Course.wav"), NULL, SND_FILENAME | SND_ASYNC);

	while (game->running())
	{
		frame_start = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frame_time = SDL_GetTicks() - frame_start;

		if (frame_delay > frame_time) {
			SDL_Delay(frame_delay - frame_time);
		}
	}

	game->clean();

	return 0;
}