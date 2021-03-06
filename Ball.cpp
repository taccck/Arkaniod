#include "Ball.h"
#include "Sprite.h"
#include "GameObject.h"
#include "BoxCollider.h"
#include <vector>

void Bounce(GameObject* self, GameObject* collided, Vector2<float> normal)
{
	MovingBody* currBall = self->GetComponent<MovingBody>();
	Vector2<float> currVelocity = currBall->velocity;
	float scalarProjection = normal.x * currVelocity.x + normal.y * currVelocity.y;
	Vector2<float> reflection{ currVelocity.x - 2 * normal.x * scalarProjection, currVelocity.y - 2 * normal.y * scalarProjection };
	currBall->velocity = reflection;
}

void Ball(Level* lvl)
{
	for (size_t i = 0; i < 2; i++)
	{
		GameObject* gameObject = new GameObject();
		gameObject->transform->SetPosition({ screenWidth / 200.f + i, screenHeight / 200.f });
		gameObject->transform->SetScale({ 4,4 });
		Sprite* sprite = new Sprite("Art//PlayerChar.png", gameObject);
		BoxCollider* collider = new BoxCollider(gameObject, { (float)sprite->w, (float)sprite->h });
		collider->physicBody = true;
		MovingBody* body = new MovingBody(gameObject);
		gameObject->AddComponent(sprite);
		gameObject->AddComponent(collider);
		gameObject->AddComponent(body);
		collider->OnCollision = Bounce;
		body->velocity.x = 5.f;
		body->velocity.y = -5.f;
		lvl->AddGameObject(gameObject);
	}
}