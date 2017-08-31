#include "FlyCam.h"
#include <cassert>


FlyCam::FlyCam()
{
}


FlyCam::~FlyCam()
{
}

void FlyCam::Start()
{
}

void FlyCam::Update()
{
}

void FlyCam::Run()
{
}

mat4 FlyCam::lookat(vec3 eye, vec3 center, vec3 up)
{
	vec3 f = eye - center;
	z = normalize(f);
	vec3 s = cross(up, z);
	x = normalize(s);
	vec3 u = cross(z, x);
	y = normalize(u);
	view = mat4(x.x, x.y, x.z, 0, y.x, y.y, y.z, 0, z.x, z.y, z.z, 0, 0, 0, 0, 1);
	translation = mat4(1, 0, 0, -eye.x, 0, 1, 0, -eye.y, 0, 0, 1, -eye.z, 0, 0, 0, 1);
	view *= translation;
	world = inverse(view);
	return view;
}

void test()
{
	vec3 a = vec3(1, 2, 3);
	vec3 b = vec3(3, 2, 1);
	vec3 c = vec3(2, 3, 1);
},