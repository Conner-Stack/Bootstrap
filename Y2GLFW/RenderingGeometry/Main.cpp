#include <iostream>
#include <glm\glm.hpp>


using namespace glm;
struct Vertex
{
	vec4 position;
	vec4 Color;
};

void generateGrid(unsigned int rows, unsigned int cols )
{
	Vertex* aoVertices = new Vertex[rows + cols];
	for (unsigned int r = 0; r < rows; ++r)
	{
		for (unsigned int c = 0; c < cols; ++c)
		{
			aoVertices[r * cols + c].position = vec4((float)c, 0, (float)r, 1);
			vec3 color = vec3(sinf((c / (float)(cols - 1))* (r / (float)(rows - 1))));
			aoVertices[r*cols + c].Color = vec4(color, 1);
		}
	}
	delete[] aoVertices;
}