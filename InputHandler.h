#pragma once
#include "GamerTools.h"
#include <SDL.h>

void UpdateInput(bool&);

extern bool keys[SDL_NUM_SCANCODES];
extern bool button[3];
extern Vector2<float> mousePosistion;
extern Vector2<int> arrowKeys;