#include "Paddle.h"
#include "Renderer.h"
#include "Sprite.h"
#include "BoxCollider.h"
#include "MovingBody.h"
#include "PaddleMove.h"

void Paddle(Level* lvl)
{
	GameObject* gameObject = new GameObject();
	gameObject->transform->SetPosition({ screenWidth / 200.f, screenHeight / 800.f });
	gameObject->transform->SetScale({ 4.f, 1.f });
	Sprite* sprite = new Sprite("Art//PlayerSprite.png", gameObject);
	BoxCollider* collider = new BoxCollider(gameObject, { (float)sprite->w, (float)sprite->h });
	PaddleMove* paddleMove = new PaddleMove(gameObject);
	gameObject->AddComponent(paddleMove);
	gameObject->AddComponent(sprite);
	gameObject->AddComponent(collider);

	lvl->AddGameObject(gameObject);
}