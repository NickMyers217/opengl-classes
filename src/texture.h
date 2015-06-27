#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

class Texture
{
private:
	unsigned char * m_data;

public:
	GLuint m_id;
	int m_unit;
	int m_width;
	int m_height;
	int m_numComponents;

	Texture(const char * path, int unit);
	~Texture();

	void use();

	inline unsigned char * getData() { return m_data; }
};

#endif