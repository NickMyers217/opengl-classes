#include <GL/glew.h>
#include <assert.h>
#include <iostream>
#include "screen.h"


Screen::Screen(int width, int height)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	m_width = width;
	m_height = height;
	m_window = nullptr;
	m_mouseCaptured = false;
	m_window = SDL_CreateWindow("OpenGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN);
	assert(m_window != nullptr);
	m_context = SDL_GL_CreateContext(m_window);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glewExperimental = true;
	GLenum glewStatus = glewInit();
	assert(glewStatus == GLEW_OK);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LESS);
	std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}


Screen::~Screen()
{
	SDL_GL_DeleteContext(m_context);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}


void Screen::clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void Screen::swap()
{
	SDL_GL_SwapWindow(m_window);
}


bool Screen::isOpen()
{
	if (m_state == OPEN) return true;
	else return false;
}


void Screen::open()
{
	m_state = OPEN;
}


void Screen::close()
{
	m_state = CLOSE;
}


void Screen::setMouseCapture(bool capture)
{
	if (capture && !m_mouseCaptured)
	{
		if (SDL_SetRelativeMouseMode((SDL_bool)true) == 0)
			m_mouseCaptured = true;
	}

	if (!capture && m_mouseCaptured)
	{
		if (SDL_SetRelativeMouseMode((SDL_bool)false) == 0)
			m_mouseCaptured = false;
	}
}
