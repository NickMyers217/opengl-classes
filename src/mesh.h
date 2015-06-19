#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>


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


struct Transform {
	glm::vec3 translation;	
	float angle;
	glm::vec3 axis;
	glm::vec3 scale;
	glm::mat4 modelMatrix;

	Transform() 
		: translation(glm::vec3(0.0f, 0.0f, 0.0f)),
		  axis(glm::vec3(0.0f, 1.0f, 0.0f)),
		  scale(glm::vec3(1.0f, 1.0f, 1.0f))
	{
		angle = 0.0f;
	}

	void calculate()
	{
		glm::mat4 translate = glm::translate(glm::mat4(1.0f), translation);
		glm::mat4 rotate = glm::rotate(translate, angle, axis);
		modelMatrix = glm::scale(rotate, scale);
	}
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
};

#endif
