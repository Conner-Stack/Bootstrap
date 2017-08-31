#include "Camera.h"
#include <iostream>
#include <cassert>

Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::Start() {}

void Camera::Update() {}

void Camera::Run() {}

mat4 Camera::lookat(vec3 eye, vec3 center, vec3 up) {
	vec3 f = eye - center;
	vec3 z = normalize(f);
	vec3 s = cross(up, z);
	vec3 x = normalize(s);
	vec3 u = cross(z, x);
	vec3 y = normalize(u);
	mat4 view = mat4(x.x, x.y, x.z, 0.0f, y.x, y.y, y.z, 0.0f, z.x, z.y, z.z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	mat4 translation = mat4(1.0f, 0.0f, 0.0f, -eye.x, 0.0f, 1.0f, 0.0f, -eye.y, 0.0f, 0.0f, 1.0f, -eye.z, 0.0f, 0.0f, 0.0f, 1.0f);
	view *= translation;
	return view;
}

