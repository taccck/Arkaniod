#include "PaddleMove.h"
#include "InputHandler.h"
#include "GamerTools.h"

void PaddleMove::Move()
{
	gameObject->transform->SetPosition({ mousePosistion.x , height });
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

void PaddleMove::FixedUpdate()
{
	Move();
}