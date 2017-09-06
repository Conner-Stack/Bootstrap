#pragma once
#include "Application.h"
class RenderingGeometry :
	public Application
{
public:
	RenderingGeometry();
	~RenderingGeometry();
protected:
	void startup() override;
	void shudown() override;
	void update(float) override;
	void draw() override;
};

