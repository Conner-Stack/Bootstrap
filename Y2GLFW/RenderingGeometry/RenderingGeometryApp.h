#pragma once
#include <Application.h>
#include <glm\glm.hpp>
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
protected:
	void startup() override;
	void shutdown() override;
	void update(float) override;
	void draw() override;
};

