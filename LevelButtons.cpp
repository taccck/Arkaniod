#include "LevelButtons.h"
#include "Button.h"
#include <filesystem>
#include "BaseLevel.h"
#include "Text.h"
#include "LevelThatMakesLevels.h"
#include "LevelSelection.h"
#include "Renderer.h"

void LoadFileLevel(Button* clicked)
{
	Level* newLvl = LoadLevelFromFile(clicked->name);
	currLevel->NewLevel(newLvl);
}

void LoadLevelMaker(Button* clicked)
{
	Level* newLvl = LoadLevelCreator();
	currLevel->NewLevel(newLvl);
}

void LevelButtons(Level* lvl)
{
	GameObject* newLvlButton = new GameObject();
	newLvlButton->transform->SetPosition({ 9.f, 7.5f });
	Button* makeLvlButt = new Button({ .75f, .75f }, newLvlButton, "LevelCreator");
	makeLvlButt->OnClick = LoadLevelMaker;
	Text* txt = new Text(newLvlButton, "New", { .75f, .75f });
	newLvlButton->AddComponent(makeLvlButt);
	newLvlButton->AddComponent(txt);
	lvl->AddGameObject(newLvlButton);

	int lvlCount = 0;
	for (const auto& dirEntry : std::filesystem::recursive_directory_iterator("Levels"))
	{
		std::string name = dirEntry.path().stem().string();
		int len = name.size();

		char* c = new char[len + 1];
		std::copy(name.begin(), name.end(), c);
		c[len] = '\0';
		GameObject* lvlButton = new GameObject();
		lvlButton->transform->SetPosition({ 4.f, 7.5f - lvlCount * 1.75f });
		Button* butt = new Button({ 3.5f,.75f }, lvlButton, name);
		butt->OnClick = LoadFileLevel;
		Text* text = new Text(lvlButton, c, { 3.5f,.75f });
		lvlButton->AddComponent(butt);
		lvlButton->AddComponent(text);
		lvl->AddGameObject(lvlButton);

		lvlCount++;
	}
}

void SelectionLevelLoad(Button* clicked)
{
	Level* newLvl = LoadSelectionLevel();
	currLevel->NewLevel(newLvl);
}

void BackButton(Level* level)
{
	GameObject* backGO = new GameObject();
	backGO->transform->SetPosition({ (screenWidth / 100.f) - 1 , (screenHeight / 100.f) - 1 });
	Button* backButton = new Button({ .5f, .5f }, backGO, "");
	backButton->OnClick = SelectionLevelLoad;
	Text* backTxt = new Text(backGO, "Back", { .5f, .5f });
	backGO->AddComponent(backButton);
	backGO->AddComponent(backTxt);
	level->AddGameObject(backGO);
}