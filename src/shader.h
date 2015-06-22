#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

class Shader
{
public:
	GLuint m_pid;
	GLuint m_vid;
	GLuint m_fid;

	Shader(const char * vertFile = "./res/shaders/default_vert.glsl", const char * fragFile = "./res/shaders/default_frag.glsl");
	~Shader();

	void use();
	void setUniform(const char * name, float val);
	void setUniform(const char * name, float v1, float v2);
	void setUniform(const char * name, int val);
	void setUniform(const char * name, GLfloat * val);
	void loadShaderSource(GLuint shader, const char * filePath);
	void errorCheck(GLuint id, bool isProgram);
};

#endif
