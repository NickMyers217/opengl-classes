#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "transform.h"
#include "texture.h"


struct Vertex {
	glm::vec3 point;
	glm::vec3 normal;
	glm::vec2 uv;

	Vertex(float x, float y, float z)
		: point(x, y, z),
		normal(0.0f, 0.0f, 0.0f),
		uv(0.0f, 0.0f)
	{}

	Vertex(float x, float y, float z, float nx, float ny, float nz)
		: point(x, y, z),
		normal(nx, ny, nz),
		uv(0.0f, 0.0f)
	{}

	Vertex(float x, float y, float z, float nx, float ny, float nz, float u, float v)
		: point(x, y, z),
		normal(nx, ny, nz),
		uv(u, v)
	{}
};


class Mesh
{
private:
	Transform m_transform;
	GLuint m_vao;
	GLuint m_vbo;
	std::vector<Vertex> m_verts;

public:
	Texture * m_texture;

	Mesh(Texture * texture);
	~Mesh();

	void init();
	void addVert(Vertex vert);
	void addVert(float x, float y, float z);
	void addVert(float x, float y, float z, float nx, float ny, float nz);
	void addVert(float x, float y, float z, float nx, float ny, float nz, float u, float v);
	void draw();
	void translate(float x, float y, float z);
	void translate(glm::vec3 translation);
	void rotate(float angle, bool xAxis, bool yAxis, bool zAxis);
	void rotate(float angle, glm::vec3 axis);
	void scale(float xScale, float yScale, float zScale);
	void scale(glm::vec3 scale);

	inline glm::mat4 getTransform() { return m_transform.getModelMat(); }
};

#endif
