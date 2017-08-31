#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cassert>
#pragma once
using namespace glm;

	class Camera
	{
	public:
		Camera();
		virtual ~Camera();
		mat4 lookat(vec3 eye, vec3 center, vec3 up);
		vec3 x;
		vec3 y;
		vec3 z;
		mat4 translation;
		mat4 view;
		mat4 world;
	protected:
		virtual void Start() = 0;
		virtual void Update()= 0;
		virtual void Run() = 0;
	};
