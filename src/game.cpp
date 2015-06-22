#include <iostream>
#include "primitives/cube.h"
#include "primitives/triangle.h"
#include "primitives/plane.h"
#include "game.h"

Game::Game(int width, int height, int fps)
	: m_screen(new Screen(width, height)),
	m_shader(new Shader("../res/shaders/transform_vert.glsl", "../res/shaders/color_frag.glsl")),
	m_input(new InputManager()),
	m_camera(new Camera())
{
	m_width = width;
	m_height = height;
	m_fps = fps;
	m_frametime = 1000.0 / fps;
	m_wireframe = false;
	m_meshes.push_back(Plane(20.0f, 20.0f));
	m_meshes.push_back(Cube(true));

	for (it_mesh = m_meshes.begin(); it_mesh < m_meshes.end(); it_mesh++)
	{
		it_mesh->init();
	}
}


Game::~Game()
{
	delete m_camera;
	delete m_input;
	delete m_shader;
	delete m_screen;
}


void Game::run()
{
	m_screen->open();
	m_screen->setMouseCapture(true);
	while (m_screen->isOpen())
	{
		double frameStart = (double)SDL_GetTicks();

		handleEvents();
		tick();
		render();
		capFPS(frameStart);
	}
}


void Game::handleEvents()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			m_screen->close();
			break;
		case SDL_MOUSEBUTTONDOWN:
			m_screen->setMouseCapture(true);
			break;
		case SDL_MOUSEMOTION:
			if (m_screen->isCaptured())
				m_camera->setDirection((float)e.motion.xrel, (float)e.motion.yrel);
			break;
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_screen->setMouseCapture(false);
				break;
			default:
				if (m_screen->isCaptured())
					m_input->pressKey(e.key.keysym.sym);
			}
			break;
		case SDL_KEYUP:
			if (m_screen->isCaptured())
				m_input->releaseKey(e.key.keysym.sym);
			break;
		}
	}
}


void Game::tick()
{
	if (m_input->isPressed(SDLK_a)) m_camera->setPosition(-1.0f, 0.0f, 0.0f);
	if (m_input->isPressed(SDLK_w)) m_camera->setPosition(0.0f, 0.0f, -1.0f);
	if (m_input->isPressed(SDLK_d)) m_camera->setPosition(1.0f, 0.0f, 0.0f);
	if (m_input->isPressed(SDLK_s)) m_camera->setPosition(0.0f, 0.0f, 1.0f);
	if (m_input->isPressed(SDLK_q)) m_camera->setPosition(0.0f, 1.0f, 0.0f);
	if (m_input->isPressed(SDLK_e)) m_camera->setPosition(0.0f, -1.0f, 0.0f);

	if (m_input->isPressed(SDLK_LALT) && m_input->isPressed(SDLK_F12))
	{
		if (!m_wireframe)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			m_wireframe = true;
		}
		else
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			m_wireframe = false;
		}
	}

	m_meshes[0].translate(0.0f, -1.0f, 0.0f);
	m_meshes[1].translate(10.0f, 5.0f, -10.0f);
	m_meshes[1].rotate(sinf(SDL_GetTicks() / 1000.0f), false, true, false);
}


void Game::render()
{
	m_screen->clear(0.0f, 0.0f, 0.4f, 1.0f);

	m_shader->use();
	m_shader->setUniform("projection", &m_camera->getProjectionMat()[0][0]);
	m_shader->setUniform("view", &m_camera->getViewMat()[0][0]);

	for (it_mesh = m_meshes.begin(); it_mesh < m_meshes.end(); it_mesh++)
	{
		m_shader->setUniform("model", &it_mesh->getTransform()[0][0]);
		it_mesh->draw();
	}

	m_screen->swap();
}


void Game::capFPS(double frameStart)
{
	double frameEnd, frameDiff;
	frameEnd = (double)SDL_GetTicks();
	frameDiff = frameEnd - frameStart;

	if (frameDiff < m_frametime)
	{
		SDL_Delay((Uint32)(m_frametime - frameDiff));
	}

	std::cout << 1000 / (SDL_GetTicks() - frameStart) << '\r';
}
