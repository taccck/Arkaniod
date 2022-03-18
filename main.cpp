#include "InputHandler.h"
#include "Renderer.h"
#include "LevelSelection.h"

int main(int argc, char* argv[])
{
	InitializeRenderer();
	bool playing = true;
	currLevel = LoadSelectionLevel();

	while (playing) {
		UpdateDeltaTime();
		UpdateInput(playing);

		Clear();
		currLevel->Tick();
		Present();
	}
	return 0;
}