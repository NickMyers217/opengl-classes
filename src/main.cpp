#include "game.h"


int main()
{
	Game * game = new Game();

	game->m_meshes.push_back(Mesh());
	game->m_meshes.push_back(Mesh());

	game->m_meshes[0].addVert(-1.0f, 1.0f, 0.0f);
	game->m_meshes[0].addVert(-0.5f, 1.0f, 0.0f);
	game->m_meshes[0].addVert(-1.0f, 0.5f, 0.0f);
	game->m_meshes[0].init();

	game->m_meshes[1].addVert(0.5f, -1.0f, 0.0f);
	game->m_meshes[1].addVert(1.0f, -0.5f, 0.0f);
	game->m_meshes[1].addVert(1.0f, -1.0f, 0.0f);
	game->m_meshes[1].init();

	game->run();

	delete game;

	return 0;
}
