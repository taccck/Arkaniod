#include "Title.h"
#include "Text.h"
#include "Renderer.h"

void Title(Level* level)
{
	GameObject* gameObject = new GameObject();
	gameObject->transform->SetPosition({ (float)screenWidth / 200.f, (float) screenHeight / 100.f - 1.5f });
	Text* txt = new Text(gameObject, "Game", { 9.f,1.f });
	gameObject->AddComponent(txt);
	level->AddGameObject(gameObject);
}