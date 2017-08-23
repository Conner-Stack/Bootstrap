#pragma once
#include "Camera.h"
class FlyCam :
	public Camera
{
public:
	FlyCam();
	~FlyCam();
	// Inherited via Camera
	vec3 x;
	vec3 y;
	vec3 z;

	mat3 translation;
	mat3 view;
	mat3 world;
	virtual void Start() override;
	virtual void Update() override;
	virtual void Run() override;
	mat4 lookat(vec3 eye, vec3 center, vec3 up);
};

