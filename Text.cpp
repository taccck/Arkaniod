#include "Text.h"
#include "Renderer.h"

TTF_Font* bebas;
SDL_Color White;

Text::Text(GameObject* _gameObject, const char* msg, Vector2<float> _size)
{
	gameObject = _gameObject;
	message = msg;
	size = _size;
}

void Text::Start()
{
	bebas = TTF_OpenFont("BebasNeue-Regular.ttf", 50);
	White = { 255, 255, 255 };
}

void Text::LateUpdate()
{
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(bebas, message, White);
	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_Rect Message_rect = gameObject->transform->GetRect(size.x * 100, size.y * 100);
	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}