#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../mesh.h"

class Triangle : public Mesh
{
public:
	Triangle(Texture * texture)
		: Mesh(texture)
	{
		addVert(-1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
		addVert(1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);
		addVert(0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.5f, -1.0f);
	}
};

#endif
