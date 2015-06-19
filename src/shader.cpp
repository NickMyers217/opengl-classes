#include "shader.h"


Shader::Shader(const char * vertFile, const char * fragFile)
{
	m_vid = glCreateShader(GL_VERTEX_SHADER);
	m_fid = glCreateShader(GL_FRAGMENT_SHADER);
	loadShaderSource(m_vid, vertFile);
	loadShaderSource(m_fid, fragFile);
	glCompileShader(m_vid);
	glCompileShader(m_fid);
	errorCheck(m_vid, false);
	errorCheck(m_fid, false);
	m_pid = glCreateProgram();
	glAttachShader(m_pid, m_vid);
	glAttachShader(m_pid, m_fid);
	glLinkProgram(m_pid);
	errorCheck(m_pid, true);
}


Shader::~Shader()
{
	glDetachShader(m_pid, m_fid);
	glDetachShader(m_pid, m_vid);
	glDeleteProgram(m_pid);
	glDeleteShader(m_fid);
	glDeleteShader(m_vid);
}


void Shader::use()
{
	glUseProgram(m_pid);
}


void Shader::setUniform1f(const char * name, float val)
{
	GLint loc = glGetUniformLocation(m_pid, name);
	if(loc != -1) glUniform1f(loc, val);
}


void Shader::setUniform2f(const char * name, float v1, float v2)
{
	GLint loc = glGetUniformLocationARB(m_pid, name);
	if(loc != -1) glUniform2f(loc, v1, v2);
}


void Shader::setUniform1i(const char * name, int val)
{
	GLint loc = glGetUniformLocationARB(m_pid, name);
	if(loc != -1) glUniform1i(loc, val);
}


void Shader::loadShaderSource(GLuint shader, const char * filePath)
{
	std::string source, line;
	std::ifstream file(filePath);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			source += line;
		}
		file.close();
	}
	else std::cout << "Unable to open file"; 

	GLchar * helper1 = (GLchar *) source.c_str();
	GLint helper2 = (GLint) source.length();
	glShaderSource(shader, 1, &helper1, &helper2);
}


void Shader::errorCheck(GLuint id, bool isProgram)
{
	GLint error = 0;
	if(isProgram) glGetProgramiv(id, GL_LINK_STATUS, &error);
	else glGetShaderiv(id, GL_COMPILE_STATUS, &error);

	if(error == GL_FALSE)
	{
		GLint maxLength = 0;
		if(isProgram) glGetProgramiv(id, GL_INFO_LOG_LENGTH, &maxLength);
		else glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		GLchar * errorLog = new GLchar[maxLength];
		if(isProgram) glGetProgramInfoLog(id, maxLength, &maxLength, &errorLog[0]);
		else glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

		std::cerr << errorLog << std::endl;
		delete [] errorLog;
	}
}



