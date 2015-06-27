#include <iostream>
#include "texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "util/stb_image.h"


Texture::Texture(const char * path, int unit)
{
	m_unit = unit;
	m_data = stbi_load(path, &m_width, &m_height, &m_numComponents, 4);

	if (m_data == nullptr)
		std::cerr << path << " failed to load..." << std::endl;

	glGenTextures(1, &m_id);
	glBindTexture(GL_TEXTURE_2D, m_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_data);

	stbi_image_free(m_data);
	glBindTexture(GL_TEXTURE_2D, 0);
}


Texture::~Texture()
{
	glDeleteTextures(1, &m_id);
}


void Texture::use()
{
	glActiveTexture(GL_TEXTURE0 + m_unit);
	glBindTexture(GL_TEXTURE_2D, m_id);
}