#pragma once
#include "GameObject.h"
#include <list>
#include "GamerTools.h"

class BoxCollider :
	public Component
{
private:
	Vector2<float> size{};
	BoxCollider* self = this;

	void UpdateCorners();
	bool CheckCollision();

public:
	Vector2<float>* corners{};
	Line* lines{};
	GameObject* gameObject;
	bool physicBody{ false };
	bool isColliding;
	void (*OnCollision)(GameObject*, GameObject*, Vector2<float>) = nullptr;

	BoxCollider(GameObject*, Vector2<float>);
	~BoxCollider();

	void FixedUpdate() override;
	void LateUpdate() override;
	void Destroy() override;

	Vector2<float> GetNormal(Line&, Vector2<float>&);
};

extern std::list<BoxCollider*> allColliders;
extern bool updatedThisFrame;