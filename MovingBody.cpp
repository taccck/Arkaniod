#include "MovingBody.h"

MovingBody::MovingBody(GameObject* go)
{
	gameObject = go;
}

void MovingBody::FixedUpdate()
{
	Vector2<float> pos = gameObject->transform->GetPosition();
	pos.x += velocity.x * deltaTime;
	pos.y += velocity.y * deltaTime;
	gameObject->transform->SetPosition(pos);
}