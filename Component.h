#pragma once
#include <vector>

class Component
{
public:
	virtual void Start() {};
	virtual void FixedUpdate() {};
	virtual void Update() {};
	virtual void LateUpdate() {};
	virtual void Destroy() {};
};