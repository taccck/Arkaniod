#pragma once
#include <SDL.h>

extern int screenHeight;
extern int screenWidth;

extern SDL_Window* win;
extern SDL_Renderer* renderer;

void Clear();
void Present();
void InitializeRenderer();
void DeleteRenderer();