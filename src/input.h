#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include <vector>

static const int NUM_KEYS = SDLK_SLEEP + 1;

class InputManager
{
private:
	std::vector<bool> m_keys;

public:
	InputManager()
	{
		m_keys = std::vector<bool>(NUM_KEYS, false);
		m_keys.reserve(NUM_KEYS);
	}

	~InputManager() {}

	inline void pressKey(SDL_Keycode key)
	{
		if (!m_keys[key]) m_keys[key] = true;
	}

	inline void releaseKey(SDL_Keycode key)
	{
		if (m_keys[key]) m_keys[key] = false;
	}

	inline bool isPressed(SDL_Keycode key)
	{
		return m_keys[key];
	}
};

#endif
