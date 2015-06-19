#include "mesh.h"


Mesh::Mesh()
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


void Mesh::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, m_verts.size());

	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
