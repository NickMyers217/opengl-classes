#ifndef PLANE_H
#define PLANE_H

#include "../mesh.h"

class Plane : public Mesh
{
	public:
		Plane(int sizeX = 10, int sizeZ = 10)
			: Mesh()
		{
			for(int z = 0; z < sizeZ; z++)
			{
				for(int x = 0; x < sizeX; x++)
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
