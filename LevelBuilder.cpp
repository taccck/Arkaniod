#include "LevelBuilder.h"
#include "InputHandler.h"
#include "Sprite.h"
#include "BoxCollider.h"
#include "BlockBehavior.h"

void LevelBuilder::Update()
{
	if (!button[1]) 
	{
		placedThisPress = false;
		pressedButtonThisFrame = false;
	}

	if (placedThisPress || !button[1] || pressedButtonThisFrame) return;
	placedThisPress = true;

	std::string newBlock = "";
	newBlock += placingHp + 48;
	newBlock += ",";
	newBlock += std::to_string(mousePosistion.x);
	newBlock += ",";
	newBlock += std::to_string(mousePosistion.y);
	newBlock += ",";
	newBlock += "\n";
	placedBlocks += newBlock;

	GameObject* gameObject = new GameObject();
	gameObject->transform->SetPosition(mousePosistion);
	Sprite* sprite = new Sprite("Art//EnemySprite.png", gameObject);
	BoxCollider* box = new BoxCollider(gameObject, { (float)sprite->w, (float)sprite->h });
	BlockBehavior* block = new BlockBehavior(box, gameObject, placingHp);
	gameObject->AddComponent(sprite);
	gameObject->AddComponent(box);
	gameObject->AddComponent(block);
	currLevel->AddGameObject(gameObject);
}