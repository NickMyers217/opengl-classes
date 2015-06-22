#ifndef PLANE_H
#define PLANE_H

#include "../mesh.h"

class Plane : public Mesh
{
public:
	Plane(float sizeX = 10.0f, float sizeZ = 10.0f)
		: Mesh()
	{
		for (float z = 0.0f; z < sizeZ; z++)
		{
			for (float x = 0.0f; x < sizeX; x++)
			{
				addVert(x, 0.0f, -z);
				addVert(x, 0.0f, -z - 1);
				addVert(x + 1, 0.0f, -z - 1);
				addVert(x + 1, 0.0f, -z - 1);
				addVert(x + 1, 0.0f, -z);
				addVert(x, 0.0f, -z);
			}
		}
	}
};

#endif
