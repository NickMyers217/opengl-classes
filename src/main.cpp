#include "game.h"

int main(int argc, char ** argv)
{
	Game * game = new Game(1920, 1080, 60);

	game->run();

	delete game;

	return 0;
}



