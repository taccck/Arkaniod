#include "InputHandler.h"
#include "Renderer.h"
#include "LevelSelection.h"

int main(int argc, char* argv[])
{
	InitializeRenderer();
	bool playing = true;
	currLevel = LoadSelectionLevel();

	while (playing) {
		// feedback: doesn't seem like there is any time delays and frame management in the main loop.
		UpdateDeltaTime();
		UpdateInput(playing);

		Clear();
		currLevel->Tick();
		Present();
	}
	return 0;
}