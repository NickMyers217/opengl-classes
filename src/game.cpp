#include "game.h"
#include <glm/gtc/matrix_transform.hpp>

Game::Game()
	: m_screen(new Screen(WIDTH, HEIGHT)),
	  m_shader(new Shader("./res/shaders/transform_vert.glsl", "./res/shaders/color_frag.glsl")),
	  m_camera(new Camera())
{
	m_meshes.push_back(Cube());
	m_meshes[0].init();
}


Game::~Game()
{
	delete m_camera;
	delete m_shader;
	delete m_screen;
}


void Game::run()
{
	m_screen->open();
	while(m_screen->isOpen())
	{
		double frameStart = (double) SDL_GetTicks();

		handleEvents();
		tick();
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


void Game::tick()
{
	m_meshes[0].m_transform.translation = glm::vec3(0.0f, 0.0f, -2.0f);
	m_meshes[0].m_transform.angle = sinf(SDL_GetTicks() / 1000.0f);
}


void Game::render()
{

	m_screen->clear(0.0f, 0.0f, 0.4f, 1.0f);

	m_shader->use();
	m_shader->setUniformMat4("projection", &m_camera->getProjectionMat()[0][0]);
	m_shader->setUniformMat4("view", &m_camera->getViewMat()[0][0]);

	for(it_mesh = m_meshes.begin(); it_mesh < m_meshes.end(); it_mesh++)
	{
		m_shader->setUniformMat4("model", &it_mesh->getTransform()[0][0]);
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

