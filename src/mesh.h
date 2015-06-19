#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "transform.h"


struct Vertex {
	glm::vec3 point;
	glm::vec3 color;

	Vertex(float x, float y, float z)
		: point(glm::vec3(x, y, z)),
		  color(glm::vec3(1.0f, 1.0f, 1.0f))
	{}

	Vertex(float x, float y, float z, float r, float g, float b)
		: point(glm::vec3(x, y, z)),
		  color(glm::vec3(r, g, b))
	{}
};


class Mesh
{
	public:
		GLuint m_id;
		std::vector<Vertex> m_verts;
		Transform m_transform;

		Mesh();
		~Mesh();
		void init();
		void addVert(Vertex vert);
		void addVert(float x, float y, float z);
		void addVert(float x, float y, float z, float r, float g, float b);
		void draw();

		glm::mat4 getTransform() {
			return m_transform.getModelMat();
		}
};

#endif
