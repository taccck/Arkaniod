#include "PaddleMove.h"
#include "InputHandler.h"
#include "GamerTools.h"

void PaddleMove::Move()
{
	float oldPos = gameObject->transform->GetPosition().x;
	float newPos = mousePosistion.x;
 	gameObject->transform->SetPosition({ newPos , height });
	Vector2<float>* Sweep = collider->Sweep();
	if (Sweep != nullptr) //reset position if nothing was hit
		gameObject->transform->SetPosition({ oldPos , height });
}

PaddleMove::PaddleMove(GameObject* go)
{
	gameObject = go;
}

void PaddleMove::Start()
{
	height = gameObject->transform->GetPosition().y;
	collider = gameObject->GetComponent<BoxCollider>();
	collider->physicBody = true;
}

void PaddleMove::Update()
{
}

void PaddleMove::FixedUpdate()
{
	Move();
}

void PaddleMove::LateUpdate()
{
}

void PaddleMove::Destroy()
{
}