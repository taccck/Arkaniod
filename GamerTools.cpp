#include "GamerTools.h"
#include <SDL.h>

float deltaTime{};
const float fixedDeltaTime{ .02f }; // feedback: not used anywhere. Not sure if fixed update function is used in any of game objects either..
Uint64 previous_ticks = SDL_GetPerformanceCounter();

void UpdateDeltaTime()
{
	Uint64 ticks = SDL_GetPerformanceCounter();
	Uint64 deltaTicks = ticks - previous_ticks;
	previous_ticks = ticks;
	deltaTime = (float)deltaTicks / SDL_GetPerformanceFrequency();
}