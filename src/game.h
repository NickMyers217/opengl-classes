#ifndef GAME_H
#define GAME_H

#include <vector>
#include "screen.h"
#include "shader.h"
#include "mesh.h"
#include "camera.h"
#include "primitives/triangle.h"

const int WIDTH = 1920;
const int HEIGHT = 1080;
const int FPS = 60;
const double FRAME_TIME = 1000 / FPS;

class Game
{
	public:
		Screen * m_screen;
		Shader * m_shader;
		std::vector<Mesh> m_meshes;
		std::vector<Mesh>::iterator it_mesh;
		Camera * m_camera;

		Game();
		~Game();
		void run();
		void handleEvents();
		void tick();
		void render();
		void capFPS(double frameStart);
};

#endif
