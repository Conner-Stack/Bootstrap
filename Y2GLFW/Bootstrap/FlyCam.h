#pragma once
#include "Camera.h"
class FlyCam :
	public Camera
{
public:
	FlyCam();
	~FlyCam();
	// Inherited via Camera
	virtual void Start() override;
	virtual void Update() override;
	virtual void Run() override;
};

