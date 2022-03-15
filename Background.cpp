#include "Background.h"
#include "Sprite.h"
#include "BoxCollider.h"

void Background(Level* lvl)
{
	GameObject* background = new GameObject();
	Sprite* backSprite = new Sprite("Art//NightSkyBackground.png", background);
	background->AddComponent(backSprite);
	background->transform->SetPosition({ screenWidth / 200.f, screenHeight / 200.f });
	background->transform->SetScale(Vector2<float>{ (screenWidth / (float)(*backSprite).w), (screenHeight / (float)(*backSprite).h) });

	GameObject* topTrans = new GameObject();
	topTrans->transform->SetPosition({ screenWidth / 200.f, screenHeight / 100.f });
	BoxCollider* topBounds = new BoxCollider(topTrans, { (float)screenWidth - 20, 10 });
	topTrans->AddComponent(topBounds);

	GameObject* botTrans = new GameObject();
	botTrans->transform->SetPosition({ screenWidth / 200.f, 0.f });
	BoxCollider* botBounds = new BoxCollider(botTrans, { (float)screenWidth - 20, 10 });
	botTrans->AddComponent(botBounds);

	GameObject* rightTrans = new GameObject();
	rightTrans->transform->SetPosition({ screenWidth / 100.f, screenHeight / 200.f });
	BoxCollider* rightBounds = new BoxCollider(rightTrans, { 10, (float)screenHeight - 20 });
	rightTrans->AddComponent(rightBounds);

	GameObject* leftTrans = new GameObject();
	leftTrans->transform->SetPosition({ 0.f, screenHeight / 200.f });
	BoxCollider* leftBounds = new BoxCollider(leftTrans, { 10, (float)screenHeight - 20 });
	leftTrans->AddComponent(leftBounds);

	lvl->AddGameObject(background);
	lvl->AddGameObject(topTrans);
	lvl->AddGameObject(botTrans);
	lvl->AddGameObject(rightTrans);
	lvl->AddGameObject(leftTrans);
}