#include <iostream>
#include "primitives/cube.h"
#include "primitives/triangle.h"
#include "primitives/plane.h"
#include "game.h"

Game::Game()
	: m_screen(new Screen(WIDTH, HEIGHT)),
	  m_shader(new Shader("./res/shaders/transform_vert.glsl", "./res/shaders/color_frag.glsl")),
	  m_camera(new Camera()),
	  m_input(new InputManager())
{
	m_meshes.push_back(Cube());
	m_meshes.push_back(Plane(20, 20));

	for(it_mesh = m_meshes.begin(); it_mesh < m_meshes.end(); it_mesh++)
	{
		it_mesh->init();
	}
}


Game::~Game()
{
	delete m_input;
	delete m_camera;
	delete m_shader;
	delete m_screen;
}


void Game::run()
{
	m_screen->open();
	m_screen->setMouseCapture(true);
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
			case SDL_MOUSEBUTTONDOWN:
				m_screen->setMouseCapture(true);
				break;
			case SDL_MOUSEMOTION:
				m_camera->setDirection(e.motion.xrel, e.motion.yrel);
				break;
			case SDL_KEYDOWN:
				switch(e.key.keysym.sym)
				{
					case SDLK_ESCAPE: 
						m_screen->setMouseCapture(false);
						break;
					default:
						m_input->pressKey(e.key.keysym.sym);
				}
				break;
			case SDL_KEYUP:
				m_input->releaseKey(e.key.keysym.sym);
				break;
		}
	}
}


void Game::tick()
{
	if(m_input->isPressed(SDLK_a)) m_camera->setPosition(-1.0f,  0.0f,  0.0f);
	if(m_input->isPressed(SDLK_w)) m_camera->setPosition( 0.0f,  0.0f, -1.0f);
	if(m_input->isPressed(SDLK_d)) m_camera->setPosition( 1.0f,  0.0f,  0.0f);
	if(m_input->isPressed(SDLK_s)) m_camera->setPosition( 0.0f,  0.0f,  1.0f);
	if(m_input->isPressed(SDLK_q)) m_camera->setPosition( 0.0f,  1.0f,  0.0f);
	if(m_input->isPressed(SDLK_e)) m_camera->setPosition( 0.0f, -1.0f,  0.0f);

	m_meshes[0].translate(10.0f, 5.0f, -10.0f);
	m_meshes[0].rotate(sinf(SDL_GetTicks() / 1000.0f), false, true, false);
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
