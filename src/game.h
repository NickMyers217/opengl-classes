#ifndef GAME_H
#define GAME_H

#include <vector>
#include "screen.h"
#include "shader.h"
#include "mesh.h"
#include "camera.h"
#include "input.h"
#include "texture.h"

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
	InputManager * m_input;

	// Scene
	Shader * m_shader;
	Camera * m_camera;
	std::vector<Texture *> m_textures;
	std::vector<Texture *>::iterator it_texture;
	Texture test;
	std::vector<Mesh> m_meshes;
	std::vector<Mesh>::iterator it_mesh;

	Game(int width, int height, int fps);
	~Game();
	void run();
	void handleEvents();
	void tick();
	void render();
	void capFPS(double frameStart);
};

#endif
