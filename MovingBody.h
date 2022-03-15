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

	void Start() override;
	void Update() override;
	void FixedUpdate() override;
	void LateUpdate() override;
	void Destroy() override;
};