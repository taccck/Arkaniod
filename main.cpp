#include "InputHandler.h"
#include "Renderer.h"
#include "Paddle.h"
#include "Ball.h"
#include "Background.h"
#include "Block.h"

int main(int argc, char* argv[]) {
	InitializeRenderer();

	bool playing = true;

	Level* gameLvl = new Level();
	Background(gameLvl);
	Paddle(gameLvl);
	Ball(gameLvl);
	Blocks(gameLvl, 4,10);
	gameLvl->Start();

	while (playing) {
		UpdateDeltaTime();
		UpdateInput(playing);

		Clear();
		gameLvl->Tick();
		Present();
	}

	DeleteRenderer();
	delete gameLvl;

	return 0;
}