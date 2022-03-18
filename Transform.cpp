#include "Transform.h"
#include "cmath"
#include "Renderer.h"

Vector2<float> Transform::GetUp()
{
	return up;
}

Vector2<float> Transform::GetRight()
{
	return right;
}

Vector2<float> Transform::GetPosition()
{
	return worldPos;
}

void Transform::SetPosition(Vector2<float> position)
{
	worldPos = position;
}

float Transform::GetRotation()
{
	float rightMag = Vector2<float>::Magnitude(right);
	return cos((right.x / rightMag));
}

void Transform::SetRotation(float radians)
{
	Vector2<float> scale = GetScale();
	Vector2<float> newRight = { cos(radians), sin(radians) };
	right = { newRight.x * scale.x,  newRight.y * scale.x };
	Vector2<float> newUp = { newRight.y, newRight.x };
	up = { newRight.x * scale.y,  newRight.y * scale.y };
}

Vector2<float> Transform::GetScale()
{
	Vector2<float> scale;
	scale.x = Vector2<float>::Magnitude(right);
	scale.y = Vector2<float>::Magnitude(up);
	return scale;
}

Vector2<float> Transform::GetPixels(float sizeX, float sizeY)
{
	Vector2<float> scale = GetScale();
	return { sizeX * scale.x * 2 , sizeY * scale.y * 2 };
}

void Transform::SetScale(Vector2<float> scale)
{
	Vector2<float> oldScale = GetScale();

	Vector2<float> newScale = { scale.x / oldScale.x , scale.y / oldScale.y };

	right = { right.x * newScale.x, right.y * newScale.x };
	up = { up.x * newScale.y, up.y * newScale.y };
}

SDL_Rect Transform::GetRect(float sizeX, float sizeY)
{
	Vector2<float> scale = GetScale();
	Vector2<int> screenPos = Vector2<int>(((worldPos.x) * 100), ((worldPos.y) * 100));
	screenPos.y = screenHeight - screenPos.y;
	Vector2<float> pixelSize = GetPixels(sizeX, sizeY);
	SDL_Rect transRect = { screenPos.x - scale.x * sizeX, screenPos.y - scale.y * sizeY,
		pixelSize.x, pixelSize.y };
	return transRect;
}