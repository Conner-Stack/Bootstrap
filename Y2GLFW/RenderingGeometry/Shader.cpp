#include "Shader.h"



Shader::Shader()
{
}


Shader::~Shader()
{
}

void Shader::bind()
{
	
}

void Shader::unbind()
{
	
}

void Shader::defaultLoad()
{
	const char* vsSource = "#version 410\n \
							layout(location=0) in vec4 position; \
							layout(location=1) in vec4 color; \
							out vec4 vColor; \
							uniform mat4 projectionViewWorldMatrix; \
							void main() {vColor = color; gl_Position = projectionViewWorldMatrix * position;}";

	const char* fsSource = "#version 410\n \
						   in vec4 vColor; \
						   out vec4 fragColor; \
						   void main() {fragColor = vColor; }";

	int success = GL_FALSE;
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, (const char**)&vsSource, 0);
	glCompileShader(vertexShader);
	glShaderSource(fragmentShader, 1, (const char**)&fsSource, 0);
	glCompileShader(fragmentShader);

	m_program = glCreateProgram();
	glAttachShader(m_program, vertexShader);
	glAttachShader(m_program, fragmentShader);
	glLinkProgram(m_program);
	glGetProgramiv(m_program, GL_LINK_STATUS, &success);
	if (success == GL_FALSE) {
		int infoLogLength = 0;
		glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &infoLogLength);
		char*infoLog = new char[infoLogLength];
		glGetProgramInfoLog(m_program, infoLogLength, 0, infoLog);
		printf("Error: Failed to link shader program!\n");
		printf("%s\n", infoLog);
		delete[] infoLog;
		glDeleteShader(fragmentShader);
		glDeleteShader(vertexShader);
	}




}

unsigned int Shader::getUniform(const char * value)
{
	
}

