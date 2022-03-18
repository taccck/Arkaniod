#include "LevelThatMakesLevels.h"
#include "LevelBuilder.h"
#include "Background.h"
#include "LevelCreatorButtons.h"
#include "LevelButtons.h"

Level* LoadLevelCreator()
{
	Level* level = new Level();
	GameObject* levelCreator = new GameObject();
	LevelBuilder* levelBuilder = new LevelBuilder();
	levelCreator->AddComponent(levelBuilder);
	Background(level);
	LevelCreatorButtons(level, levelBuilder);
	BackButton(level);
	level->AddGameObject(levelCreator);
	level->Start();
	return level;
}