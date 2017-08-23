#include "FlyCam.h"



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
		
}

