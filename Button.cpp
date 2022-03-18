#include "Button.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "SDL.h"

Button::Button(Vector2<float> _size, GameObject* _gameObject, std::string _name)
{
	size = _size;
	gameObject = _gameObject;
	state = 0;
	name = _name;
}

void Button::Update()
{
	state = 0;
	Vector2<float> pos = gameObject->transform->GetPosition();
	Vector2<float> rightTop = { pos.x + size.x , pos.y + size.y };
	Vector2<float> leftBot = { pos.x - size.x, pos.y - size.y };
	bool inBounds = mousePosistion.x >= leftBot.x &&
		mousePosistion.x <= rightTop.x &&
		mousePosistion.y >= leftBot.y &&
		mousePosistion.y <= rightTop.y;
	if (!inBounds) return;

	state = 1;
	if (!button[1]) return;

	state = 2;
	if (OnClick != nullptr)
		OnClick(self);
}

void Button::LateUpdate()
{
	switch (state)
	{
	case 0:
		SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
		break;
	case 1:
		SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
		break;
	case 2:
		SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
		break;
	}
	SDL_Rect rectButt = SDL_Rect(gameObject->transform->GetRect(size.x * 100, size.y * 100));
	SDL_RenderFillRect(renderer, &rectButt);
}