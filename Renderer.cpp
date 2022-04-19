#include "Renderer.h"
#include "SDL_ttf.h"

int screenHeight{};
int screenWidth{};

SDL_Window* win = nullptr;
SDL_Renderer* renderer = nullptr;

void Clear()
{
	SDL_RenderClear(renderer);
}

void Present()
{
	SDL_RenderPresent(renderer);
}

void InitializeRenderer()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	screenWidth = DM.w;
	screenHeight = DM.h;

	win = SDL_CreateWindow("Arkaniod", 0, 0, screenWidth, screenHeight, 0);
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	TTF_Init();
}

void DeleteRenderer()
{
	// feedback: doesn't look like this is called from anywhere
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
}