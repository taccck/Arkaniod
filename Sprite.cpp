#include "Sprite.h"
#include <iostream>

Sprite::Sprite(const char* path, GameObject* go)
{ 
	imgPath = path;
	gameObject = go;

	img = IMG_LoadTexture(renderer, imgPath);

	SDL_QueryTexture(img, NULL, NULL, &w, &h);
	sizeX = w / 2;
	sizeY = h / 2;
	texr.x = 0; texr.y = 0; texr.w = w; texr.h = h;
}

void Sprite::Start()
{
}

void Sprite::Update()
{
}

void Sprite::FixedUpdate()
{

}

void Sprite::LateUpdate()
{
	texr = gameObject->transform->GetRect(sizeX, sizeY);
	SDL_RenderCopy(renderer, img, NULL, &texr);
}

void Sprite::Destroy()
{
	SDL_DestroyTexture(img);
}
