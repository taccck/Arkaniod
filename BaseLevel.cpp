#include "BaseLevel.h"
#include "Paddle.h"
#include "Ball.h"
#include "Background.h"
#include "Block.h"
#include "LevelButtons.h"

Level* LoadLevelFromFile(std::string levelName)
{
	Level* baseLevel = new Level();
	Background(baseLevel);
	Paddle(baseLevel);
	Ball(baseLevel);
	Blocks(baseLevel, levelName);
	BackButton(baseLevel);
	baseLevel->Start(); // feedback: start called 2 times
	baseLevel->Start();
	return baseLevel;
}