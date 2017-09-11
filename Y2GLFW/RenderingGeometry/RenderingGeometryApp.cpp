#include "RenderingGeometryApp.h"
#include <vector>
#include <gl_core_4_4.h>
#include <GLFW\glfw3.h>

#include <imgui\imgui.h>
#include <imgui_impl_glfw_gl3.h>

#include <glm\glm.hpp>
#include <glm\ext.hpp>

#include "Shader.h"
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

