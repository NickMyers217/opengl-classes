#include "game.h"
#include <glm/gtc/matrix_transform.hpp>

Game::Game()
	: m_screen(new Screen(WIDTH, HEIGHT)),
	  m_shader(new Shader("./res/shaders/transform_vert.glsl", "./res/shaders/color_frag.glsl"))
{
	m_meshes.push_back(Cube());
	m_meshes[0].init();
}


Game::~Game()
{
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
	float time = sinf(SDL_GetTicks() / 1000.0f);

	m_screen->clear(0.0f, 0.0f, 0.4f, 1.0f);
	m_shader->use();

	glm::mat4 projection = glm::perspective(45.0f, 16.0f / 9.0f, 0.1f, 100.0f);
	glm::mat4 view = glm::lookAt(glm::vec3(0,5,5), glm::vec3(0,0,0), glm::vec3(0,1,0));

	m_meshes[0].m_transform.translation = glm::vec3(0.0f, 0.0f, -2.0f);
	m_meshes[0].m_transform.angle = time;
	m_meshes[0].m_transform.calculate();

	m_shader->setUniformMat4("projection", &projection[0][0]);
	m_shader->setUniformMat4("view", &view[0][0]);
	m_shader->setUniformMat4("model", &m_meshes[0].m_transform.modelMatrix[0][0]);

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

