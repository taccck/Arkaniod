#include "Block.h"
#include "Sprite.h"
#include "Renderer.h"
#include "BoxCollider.h"
#include "BlockBehavior.h"
#include <fstream>

void Blocks(Level* lvl, std::string levelName)
{
	std::ifstream fin("Levels//" + levelName + ".txt");
	std::string fileLine;
	while (std::getline(fin, fileLine))
	{
		Vector2<float> pos;
		size_t begin = 2;
		for (size_t end = 2; end < fileLine.size(); end++)
		{
			if (fileLine[end] != ',') continue;

			std::string sFloat = fileLine.substr(begin, end - 1);
			if (begin == 2) pos.x = std::stof(sFloat);
			else pos.y = std::stof(sFloat);
			begin = end + 1;
		}

		GameObject* gameObject = new GameObject();
		gameObject->transform->SetPosition(pos);
		Sprite* sprite = new Sprite("Art//EnemySprite.png", gameObject);
		BoxCollider* box = new BoxCollider(gameObject, { (float)sprite->w, (float)sprite->h });
		BlockBehavior* block = new BlockBehavior(box, gameObject, fileLine.at(0) - 48);
		gameObject->AddComponent(sprite);
		gameObject->AddComponent(box);
		gameObject->AddComponent(block);
		lvl->AddGameObject(gameObject);
	}
}