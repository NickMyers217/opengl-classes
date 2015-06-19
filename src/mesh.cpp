#include "mesh.h"


Mesh::Mesh()
	: m_transform(Transform())
{
	m_id = 0;
}


Mesh::~Mesh()
{
	if(m_id != 0)
	{
		glDeleteBuffers(1, &m_id);
	}
}


void Mesh::init()
{
	if(m_id == 0)
	{
		glGenBuffers(1, &m_id);
	}
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
	glBufferData(GL_ARRAY_BUFFER, m_verts.size() * sizeof(Vertex), &m_verts[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void Mesh::addVert(Vertex vert)
{
	m_verts.push_back(vert);
}


void Mesh::addVert(float x, float y, float z)
{
	Vertex vert = Vertex(x, y, z);
	addVert(vert);
}


void Mesh::addVert(float x, float y, float z, float r, float g, float b)
{
	Vertex vert = Vertex(x, y, z, r, g, b);
	addVert(vert);
}


void Mesh::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(sizeof(Vertex) / 2));
	glDrawArrays(GL_TRIANGLES, 0, m_verts.size());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
