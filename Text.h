#pragma once
#include "GameObject.h"
#include "SDL.h"
#include <SDL_ttf.h>


class Text :
    public Component
{
private:
	GameObject* gameObject;
	Vector2<float> size;
	const char* message;

public:
	Text(GameObject*, const char*, Vector2<float>);

	void LateUpdate() override;
	void Start() override;
};