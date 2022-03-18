#include "LevelSelection.h"
#include "Background.h"
#include "LevelButtons.h"
#include "Title.h"

Level* LoadSelectionLevel()
{
	Level* selectionLevel = new Level();
	Background(selectionLevel);
	Title(selectionLevel);
	LevelButtons(selectionLevel);
	selectionLevel->Start();
	return selectionLevel;
} 