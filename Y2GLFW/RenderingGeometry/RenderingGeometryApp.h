#pragma once
#include <Application.h>
class RenderingGeometryApp :
	public Application
{
public:
	RenderingGeometryApp();
	~RenderingGeometryApp();
protected:
	void startup() override;
	void shudown() override;
	void update(float) override;
	void draw() override;
};

