#pragma once
#include "GamerTools.h"
#include "SDL.h"

class Transform 
{
private:
	Vector2<float> worldPos;
	Vector2<float> up = { 0.0f,1.0f };
	Vector2<float> right = { 1.0f,0.0f };

public:
	Transform();

	Vector2<float> GetUp();
	Vector2<float> GetRight();

	Vector2<float> GetPosition();
	void SetPosition(Vector2<float> position);
	float GetRotation();
	void SetRotation(float radians);
	Vector2<float> GetScale();
	void SetScale(Vector2<float> scale);
	Vector2<float> GetPixels(float sizeX, float sizeY);

	SDL_Rect GetRect(float sizeX, float sizeY);
};