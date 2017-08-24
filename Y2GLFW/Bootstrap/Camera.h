#include <glm/glm.hpp>
#pragma once
using namespace glm;

	class Camera
	{
	public:
		Camera();
		virtual ~Camera();
	protected:
		vec3 x;
		vec3 y;
		vec3 z;
		virtual void Start() = 0;
		virtual void Update()= 0;
		virtual void Run() = 0;
		mat4 lookat(vec3 eye, vec3 center, vec3 up);
	};
