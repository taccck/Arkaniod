#pragma once
#include "GameObject.h"
#include "Renderer.h"
#include <SDL_image.h>

class Sprite :
	public Component
{
private:
	SDL_Texture* img;
	SDL_Rect texr;
	int sizeX, sizeY;
	const char* imgPath;

public:
	GameObject* gameObject;
	int w, h;

	Sprite(const char* path, GameObject* go);

	void Start() override;
	void Update() override;
	void FixedUpdate() override;
	void LateUpdate() override;
	void Destroy() override;
};