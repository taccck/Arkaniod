#pragma once
#include "GameObject.h"
#include "BoxCollider.h"

class PaddleMove :
	public Component
{
private:
	float height;
	BoxCollider* collider;

	void Move();

public:
	PaddleMove(GameObject* go);
	GameObject* gameObject;

	void Start() override;
	void Update() override;
	void FixedUpdate() override;
	void LateUpdate() override;
	void Destroy() override;
};