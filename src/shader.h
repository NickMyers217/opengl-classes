#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <string>

class Shader
{
	public:
		GLuint m_pid;
		GLuint m_vid;
		GLuint m_fid;

		Shader(const char * vertFile, const char * fragFile);
		~Shader();
		void use();
		void setUniform1f(const char * name, float val);
		void setUniform2f(const char * name, float v1, float v2);
		void setUniform1i(const char * name, int val);
		void loadShaderSource(GLuint shader, const char * filePath);
		void errorCheck(GLuint id, bool isProgram);
};

#endif
