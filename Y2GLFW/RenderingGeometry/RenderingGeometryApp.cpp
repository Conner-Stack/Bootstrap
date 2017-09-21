#include "RenderingGeometryApp.h"
#include <vector>
#include <gl_core_4_4.h>
#include <GLFW\glfw3.h>

#include <imgui\imgui.h>
#include <imgui_impl_glfw_gl3.h>

#include <glm\glm.hpp>
#include <glm\ext.hpp>

#include "Shader.h"
std::vector<glm::vec4>generateHalfCircle(float radius, unsigned int points)
{
	// will be used the store the points of a half circle
	std::vector<glm::vec4> halfCircle = std::vector<glm::vec4>(points);

	// loop per point to generate each slice
	for (int i = 0; i < points; i++)
	{
		// calculate slice here

		// calculate theta here

		// x = cos(theta) and y = sin(theta) would give you a horizontal half circle.
		// 				  .
		// horizontal .	      .
		// but since we are generating triangle strips and need to be rotating this half circle differently,
		// you would reverse it to orient the half circle vertically.
		// 				.
		//				   .
		// vertically 	.
		// to be correctly oriented with how we want to draw the triangle strips.		


	}
	//return the array of the points that make up the half circle
	return halfCircle;
}
std::vector<glm::vec4> rotatePoints(std::vector<glm::vec4> points, unsigned int numOfMeridians)
{
	// will be used to store enitre sphere to be returned
	std::vector<glm::vec4> wholeSphere;

	// loop per meridian
	for (int i = 0; i <= numOfMeridians; i++)
	{
		// calculate slice		
		float slice = ? ;

		// calculate phi		
		float phi = ? ;

		// loop per point
		for (int j = 0; j < points.size(); j++)
		{

			// calculate each new value of the new vec4
			// you need to figure out the math for each point 
			float newX = ? ;
			float newY = ? ;
			float newZ = ? ;
			float newW = ? ;

			// push new vec4 onto list of points that make up entire sphere
			wholeSphere.push_back(glm::vec4(newX, newY, newZ, newW));
		}
	}
	// return the array of points that make up the entire sphere
	return wholeSphere;
}
std::vector<unsigned int> RenderGeometryApp::genIndicesTriStrip(unsigned int nm, unsigned int np)
{
	// create array of unsigned ints to store the index information
	std::vector<unsigned int> indices;

	unsigned int start;
	unsigned int botLeft;
	unsigned int botRight;

	// loop for number of meridans
	for (int i = 0; i < nm; i++)
	{
		start = ? ;

		// loop for number of points
		for (int j = 0; j < np; j++)
		{
			botLeft = ? ;
			botRight = ? ;
			indices.push_back(botLeft);
			indices.push_back(botRight);
		}
		indices.push_back(0xFFFF);
	}

	// return array of indices in order to be drawn
	return indices;
}
RenderingGeometryApp::RenderingGeometryApp()
{
}

RenderingGeometryApp::~RenderingGeometryApp()
{
}

int indexCount;
void RenderingGeometryApp::startup()
{
	Vertex a = { glm::vec4(-5,  0, 0, 1)		, glm::vec4(.1, .1, .1, 1) };//bl	
	Vertex b = { glm::vec4(5,  0, 0, 1)			, glm::vec4(.1, .1, .1, 1) };//br
	Vertex c = { glm::vec4(5, -5, 0, 1)			, glm::vec4(.1, .1, .1, 1) };//tl
	Vertex d = { glm::vec4(-5, -5, 0, 1)		, glm::vec4(1, 0, 0, 1) };//tr
	Vertex e = { glm::vec4(-5,  5, 0, 1)		, glm::vec4(0, 0, 1, 1) };//tr	

	std::vector<Vertex> vertices{ a,b,c,d,e };
	std::vector<unsigned int> indices{ 0, 1, 2, 0, 2, 3, 0, 4, 1 };
	indexCount = indices.size();
	glGenVertexArrays(1, &m_VAO);

	glBindVertexArray(m_VAO);

	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_IBO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
	

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)sizeof(glm::vec4));

	
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);		
	

	m_shaderProgram = new Shader();
	m_shaderProgram->defaultLoad();
}

void RenderingGeometryApp::shutdown()
{
}

void RenderingGeometryApp::update(float dt)
{
}

void RenderingGeometryApp::draw()
{
	ImGui_ImplGlfwGL3_NewFrame();
	ImGui::Begin("menu1");
	ImGui::Text("hello world");
	ImGui::End();

	//must bind shader
	glm::mat4 view = glm::lookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	glm::mat4 proj = glm::perspective(glm::quarter_pi<float>(), 16 / 9.f, 0.1f, 1000.f);
	glm::mat4 mvp = proj * view;
	//get the uniform location from shader
	//bind the uniform location to a variable
	//Ex: mvp will be the projectionViewWorldMatrix variable to the shader

	//setup the draw call
	//1. bind the vertex array object you want to draw
	glBindVertexArray(m_VAO);
	//2. call draw on that vao by invoking glDrawElements
	glDrawElements(GL_TRIANGLE_STRIP,1,GL_UNSIGNED_INT, 0);
	//unbind the vertex array object
	glBindVertexArray(0);
	//unbind the shader program
	
}

