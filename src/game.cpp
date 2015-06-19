#include "game.h"

Game::Game()
	: m_screen(new Screen(WIDTH, HEIGHT)),
	  m_shader(new Shader("./res/shaders/vert.glsl", "./res/shaders/frag.glsl"))
{
	m_shader->use();
}


Game::~Game()
{
	delete m_shader;
	delete m_screen;
}

void Game::run()
{
	m_screen->open();
	while(m_screen->m_state == OPEN)
	{
		double frameStart = (double) SDL_GetTicks();

		handleEvents();
		render();
		capFPS(frameStart);
	}
}


void Game::handleEvents()
{
	SDL_Event e;
	while(SDL_PollEvent(&e))
	{
		switch(e.type)
		{
			case SDL_QUIT:
				m_screen->close();
				break;
		}
	}
}


void Game::render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for(it_mesh = m_meshes.begin(); it_mesh < m_meshes.end(); it_mesh++)
	{
		it_mesh->draw();
	}

	m_screen->swap();
}


void Game::capFPS(double frameStart)
{
	double frameEnd, frameDiff;
	frameEnd = (double) SDL_GetTicks();
	frameDiff = frameEnd - frameStart;
	
	if(frameDiff < FRAME_TIME)
	{
		SDL_Delay((Uint32) (FRAME_TIME - frameDiff));
		//std::cout << 1000 / (SDL_GetTicks() - frameStart) << '\n';
	}
}

