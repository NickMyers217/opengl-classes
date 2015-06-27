#ifndef CUBE_H
#define CUBE_H

#include "../mesh.h"

class Cube : public Mesh
{
public:
	Cube(Texture * texture)
		: Mesh(texture)
	{
		addVert(-1.0f, -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
		addVert(-1.0f, -1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		addVert(-1.0f, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, -1.0f);
		addVert(1.0f, 1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, -1.0f);
		addVert(-1.0f, -1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);
		addVert(-1.0f, 1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 1.0f, -1.0f);
		addVert(1.0f, -1.0f, 1.0f, 0.0f, -1.0f, 0.0f, 1.0f, -1.0f);
		addVert(-1.0f, -1.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f);
		addVert(1.0f, -1.0f, -1.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f);
		addVert(1.0f, 1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, -1.0f);
		addVert(1.0f, -1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);
		addVert(-1.0f, -1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);
		addVert(-1.0f, -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
		addVert(-1.0f, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, -1.0f);
		addVert(-1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, -1.0f);
		addVert(1.0f, -1.0f, 1.0f, 0.0f, -1.0f, 0.0f, 1.0f, -1.0f);
		addVert(-1.0f, -1.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f);
		addVert(-1.0f, -1.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f);
		addVert(-1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, -1.0f);
		addVert(-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
		addVert(1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);
		addVert(1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f);
		addVert(1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		addVert(1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, -1.0f);
		addVert(1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		addVert(1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f);
		addVert(1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
		addVert(1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
		addVert(1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f, -1.0f);
		addVert(-1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f);
		addVert(1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
		addVert(-1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f);
		addVert(-1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
		addVert(1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, -1.0f);
		addVert(-1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, -1.0f);
		addVert(1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);
	}
};

#endif
