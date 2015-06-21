#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <glm/glm.hpp>
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
	private:
		Transform m_transform;

	public:
		GLuint m_id;
		std::vector<Vertex> m_verts;

		Mesh();
		~Mesh();

		void init();
		void addVert(Vertex vert);
		void addVert(float x, float y, float z);
		void addVert(float x, float y, float z, float r, float g, float b);
		void draw();
		void translate(float x, float y, float z);
		void translate(glm::vec3 translation);
		void rotate(float angle, bool xAxis, bool yAxis, bool zAxis);
		void rotate(float angle, glm::vec3 axis);
		void scale(float xScale, float yScale, float zScale);
		void scale(glm::vec3 scale);

		glm::mat4 getTransform() { return m_transform.getModelMat(); }
};

#endif
