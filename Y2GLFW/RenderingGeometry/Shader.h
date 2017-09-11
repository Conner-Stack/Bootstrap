#pragma once
#include <gl_core_4_4.h>
#include <cstdio>
class Shader
{
public:
	unsigned int m_programID;
	Shader();
	~Shader();
	void bind();
	void unbind();
	void load(const char* filename, unsigned int type);
	void attach();
	void defaultLoad();
	//void load();
	unsigned int getUniform(const char *);
	unsigned int m_vertexshader;
	unsigned int m_fragmentShader;
	const char* vsSource;
	const char* fsSource;
private:
	unsigned int m_program;
};

