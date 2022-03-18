#pragma once
#include "GameObject.h"
#include "GamerTools.h"


class MovingBody :
	public Component
{
public:
	GameObject* gameObject;
	Vector2<float> velocity;

	MovingBody(GameObject* go);

	void FixedUpdate() override;
};