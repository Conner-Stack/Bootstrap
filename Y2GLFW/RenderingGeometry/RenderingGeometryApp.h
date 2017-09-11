#pragma once
#include <Application.h>
#include <glm\glm.hpp>
class Shader;
struct Vertex
{
	glm::vec4 position;
	glm::vec4 color;
};
class RenderingGeometryApp :
	public Application
{
public:
	RenderingGeometryApp();
	~RenderingGeometryApp();	
	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_IBO;
protected:
	void startup() override;
	void shutdown() override;
	void update(float dt) override;
	void draw() override;

	Shader * m_shaderProgram;
};

