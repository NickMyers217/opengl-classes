#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "screen.h"
#include "shader.h"
#include "mesh.h"

const int WIDTH = 800;
const int HEIGHT = 600;
const int FPS = 60;
const double FRAME_TIME = 1000 / FPS;

class Game
{
	public:
		Screen * m_screen;
		Shader * m_shader;
		std::vector<Mesh> m_meshes;
		std::vector<Mesh>::iterator it_mesh;

		Game();
		~Game();
		void run();
		void handleEvents();
		void render();
		void capFPS(double frameStart);
};

#endif
