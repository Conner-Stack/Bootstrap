#include <iostream>
#include <glm/glm.hpp>
#include "RenderingGeometryApp.h"

int main()
{
	Application * app = new RenderingGeometryApp();
	app->run("rendering geometry", 800, 600, false);
	delete app;
}