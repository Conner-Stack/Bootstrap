#include "Camera.h"


Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::Start() {}

void Camera::Update() {}

void Camera::Run() {}

mat4 lookat(vec3 eye, vec3 center, vec3 up)
{
	vec3 f = eye - center;
	= normalize(f);
	vec3 s = cross(up, z);
	x = normalize(s);
	vec3 u = cross(z, x);
	y = normalize(u);
	view = mat4(x.x, x.y, x.z, 0, y.x, y.y, y.z, 0, z.x, z.y, z.z, 0, 0, 0, 0, 1);
	translation = mat4(1, 0, 0, -eye.x, 0, 1, 0, -eye.y, 0, 0, 1, -eye.z, 0, 0, 0, 1);
	view *= translation;
	world = inverse(view);
	
}
