#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>

enum State { OPEN, CLOSE };

class Screen
{
	private:
		bool m_mouseCaptured;

	public:
		int m_width;
		int m_height;
		SDL_Window * m_window;
		SDL_GLContext m_context;
		State m_state;

		Screen(int width, int height);
		~Screen();
		void clear(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f);
		void swap();
		bool isOpen();
		void open();
		void close();
		void setMouseCapture(bool capture);
};

#endif
