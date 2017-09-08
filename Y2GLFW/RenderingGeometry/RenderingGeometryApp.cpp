#include "RenderingGeometryApp.h"
#include <vector>
#include <imgui\imgui.h>
#include <imgui_impl_glfw_gl3.h>
RenderingGeometryApp::RenderingGeometryApp()
{
}

RenderingGeometryApp::~RenderingGeometryApp()
{
}

void RenderingGeometryApp::startup()
{
	Vertex a = { glm::vec4(-5,  0, 0, 1)		, glm::vec4(.1, .1, .1, 1) };//bl	
	Vertex b = { glm::vec4(5,  0, 0, 1)			, glm::vec4(.1, .1, .1, 1) };//br
	Vertex c = { glm::vec4(5, -5, 0, 1)			, glm::vec4(.1, .1, .1, 1) };//tl
	Vertex d = { glm::vec4(-5, -5, 0, 1)		, glm::vec4(1, 0, 0, 1) };//tr
	Vertex e = { glm::vec4(-5,  5, 0, 1)		, glm::vec4(0, 0, 1, 1) };//tr	

	std::vector<Vertex> vertices{ a,b,c,d,e };
	std::vector<unsigned int> indices{ 0, 1, 2, 0, 2, 3, 0, 4, 1 };
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
}
