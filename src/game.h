#ifndef GAME_H
#define GAME_H

#include <vector>
#include "screen.h"
#include "shader.h"
#include "mesh.h"
#include "camera.h"
#include "input.h"


class Game
{
private:
	int m_width;
	int m_height;
	int m_fps;
	double m_frametime;
	bool m_wireframe;

public:
	Screen * m_screen;
	Shader * m_shader;
	std::vector<Mesh> m_meshes;
	std::vector<Mesh>::iterator it_mesh;
	InputManager * m_input;
	Camera * m_camera;

	Game(int width, int height, int fps);
	~Game();
	void run();
	void handleEvents();
	void tick();
	void render();
	void capFPS(double frameStart);
};

#endif
