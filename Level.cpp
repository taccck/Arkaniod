#include "Level.h"
#include <algorithm>

Level* currLevel;

Level::Level()
{
	gameObjects;
	gameObjectsToDelete;
}

void Level::AddGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
}

void Level::RemoveGameObject(GameObject* gameObject)
{
	gameObjectsToDelete.push_back(gameObject);
}

void Level::NewLevel(Level* lvl)
{
	currLevel = lvl;
	Destroy();
}

void Level::Tick()
{
	Update();
	FixedUpdate();
	LateUpdate();
	DeleteMarked();
	LoadNewLevel();
}

void Level::Start()
{
	for (GameObject* gameObject : gameObjects)
		gameObject->Start();
}

void Level::Update()
{
	for (GameObject* gameObject : gameObjects)
		gameObject->Update();
}

void Level::FixedUpdate()
{
	for (GameObject* gameObject : gameObjects)
		gameObject->FixedUpdate();
}

void Level::LateUpdate()
{
	for (GameObject* gameObject : gameObjects)
		gameObject->LateUpdate();
}

void Level::Destroy()
{
	for (GameObject* gameObject : gameObjects)
		gameObjectsToDelete.push_back(gameObject);
}

void Level::DeleteMarked()
{
	if (gameObjectsToDelete.size() == 0) return;

	for (GameObject* go : gameObjectsToDelete)
	{
		gameObjects.remove(go);
		delete go;
	}
	gameObjectsToDelete.clear();
}

void Level::LoadNewLevel()
{
	if (currLevel != self)
		delete self; // feedback: while it is legal to delete "this" from compiler point of view, I'd say this is an ask for trouble.
					 // especially considering this function is called LoadNewLevel. This is a high chance that this instance will be used
					 // used after it is being deleted. This will result in pure UB
}