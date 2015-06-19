#include "screen.h"
#include <assert.h>


Screen::Screen(int width, int height)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	m_width = width;
	m_height = height;
	m_window = nullptr;
	m_window = SDL_CreateWindow(
			"OpenGL",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			m_width,
			m_height,
			SDL_WINDOW_OPENGL);
	assert(m_window != nullptr);
	m_context = SDL_GL_CreateContext(m_window);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	GLenum glewStatus = glewInit();
	assert(glewStatus == GLEW_OK);
}


Screen::~Screen()
{
	SDL_GL_DeleteContext(m_context);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}


void Screen::swap()
{
	SDL_GL_SwapWindow(m_window);
}


void Screen::open()
{
	m_state = OPEN;
}


void Screen::close()
{
	m_state = CLOSE;
}
