#include "LevelCreatorButtons.h"
#include "Button.h"
#include "Text.h"
#include "Renderer.h"
#include <fstream>

LevelBuilder* lvlBuilder;

void SetBlockHp(Button* clicked)
{
	lvlBuilder->placingHp = (int)clicked->name.at(0) - 48;
	lvlBuilder->pressedButtonThisFrame = true;
}

void Save(Button* clicked)
{
	std::ofstream out("Levels//Player Made Lvl.txt");
	out << lvlBuilder->placedBlocks;
	out.close();
	lvlBuilder->pressedButtonThisFrame = true;
}

void LevelCreatorButtons(Level* level, LevelBuilder* _lvlBuilder)
{
	lvlBuilder = _lvlBuilder;
	for (size_t i = 1; i <= 4; i++)
	{
		GameObject* hpBlockGO = new GameObject();
		hpBlockGO->transform->SetPosition({ 1.f, (float)i });
		Button* hpBlockButton = new Button({ .5f, .5f }, hpBlockGO, std::string(new char(i + 48)));
		hpBlockButton->OnClick = SetBlockHp;
		char* c = new char[2];
		c[0] = char(i + 48);
		c[1] = '\0';
		Text* hpBlockTxt = new Text(hpBlockGO, c, { .5f, .5f });
		hpBlockGO->AddComponent(hpBlockButton);
		hpBlockGO->AddComponent(hpBlockTxt);
		level->AddGameObject(hpBlockGO);
	}

	GameObject* saveGO = new GameObject();
	saveGO->transform->SetPosition({ (screenWidth / 100.f) - 1 , 1.f });
	Button* saveButton = new Button({ .5f, .5f }, saveGO, "");
	saveButton->OnClick = Save;
	Text* saveTxt = new Text(saveGO, "Save", { .5f, .5f });
	saveGO->AddComponent(saveButton);
	saveGO->AddComponent(saveTxt);
	level->AddGameObject(saveGO);
}