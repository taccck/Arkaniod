#include "InputHandler.h"
#include "Renderer.h"

Vector2<float> mousePosistion{};
Vector2<int> arrowKeys{};
bool keys[SDL_NUM_SCANCODES] = { false };

void UpdateInput(bool& playing)
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
		switch (e.type)
		{

		case SDL_MOUSEMOTION:
			mousePosistion.x = e.motion.x / 100.f;
			mousePosistion.y = (screenHeight - e.motion.y) / 100.f;
			break;

		case SDL_QUIT:
			playing = false;
			break;

		case SDL_KEYDOWN:
			keys[e.key.keysym.scancode] = true;
			break;

		case SDL_KEYUP:
			keys[e.key.keysym.scancode] = false;
			break;
		}

	bool horizontal{};
	if (keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_UP])
	{
		arrowKeys.y = 1;
		horizontal = true;
	}
	if (keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_DOWN])
	{
		arrowKeys.y = -1;
		horizontal = true;
	}
	if (!horizontal)
		arrowKeys.y = 0;

	bool vertical{};
	if (keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT])
	{
		arrowKeys.x = -1;
		vertical = true;
	}
	if (keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT])
	{
		arrowKeys.x = 1;
		vertical = true;
	}
	if (!vertical)
		arrowKeys.x = 0;

	if (keys[SDL_SCANCODE_ESCAPE])
		playing = false;
}