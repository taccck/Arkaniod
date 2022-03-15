#include "Block.h"
#include "Sprite.h"
#include "Renderer.h"
#include "BoxCollider.h"
#include "BlockBehavior.h"

void Blocks(Level* lvl, int height, int width)
{
	float W = screenWidth / 100.f;
	float H = screenHeight / 200.f;

	for (size_t y = 1; y <= height; y++)
		for (size_t x = 1; x <= width; x++)
		{
			GameObject* gameObject = new GameObject();
			gameObject->transform->SetPosition({ (x / (float)(width + 1)) * W , H - ((y / (float)(height + 1)) * H) + H });
			Sprite* sprite = new Sprite("Art//EnemySprite.png", gameObject);
			BoxCollider* box = new BoxCollider(gameObject, { (float)sprite->w, (float)sprite->h });
			BlockBehavior* block = new BlockBehavior(box, height - y + 1, gameObject);
			gameObject->AddComponent(sprite);
			gameObject->AddComponent(box);
			gameObject->AddComponent(block);
			lvl->AddGameObject(gameObject);
		}
}