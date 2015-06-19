#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>


struct Vertex {
	glm::vec3 point;

	Vertex(float x, float y, float z)
		: point(glm::vec3(x, y, z))
	{}
};


class Mesh
{
	public:
		GLuint m_id;
		std::vector<Vertex> m_verts;

		Mesh();
		~Mesh();
		void init();
		void addVert(Vertex vert);
		void addVert(float x, float y, float z);
		void draw();
};

#endif
