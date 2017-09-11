#pragma once
#include <Application.h>
#include <glm\glm.hpp>
#define PI 3.14159
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
	void GenerateGrid(unsigned int rows, unsigned int cols);
	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_IBO;
protected:
	void startup() override;
	void shutdown() override;
	void update(float dt) override;
	void draw() override;
};

