#pragma once

#include <glm/glm.hpp>
using namespace glm;

	class Camera
	{
	public:
		Camera();
		virtual ~Camera();
		mat4 lookat(vec3 eye, vec3 center, vec3 up);
		vec3 m_x;
		vec3 m_y;
		vec3 m_z;
		mat4 m_translation;
		mat4 m_view;
		mat4 m_world;
		
	};
