#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>
#include <GL/glew.h>

enum State { OPEN, CLOSE };

class Screen
{
	public:
		int m_width;
		int m_height;
		SDL_Window * m_window;
		SDL_GLContext m_context;
		State m_state;

		Screen(int width, int height);
		~Screen();
		void swap();
		void open();
		void close();
};

#endif
