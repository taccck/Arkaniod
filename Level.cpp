#include "Level.h"
#include <algorithm>
#include <iostream>

Level* currLevel;

Level::Level()
{
	currLevel = self;
	gameObjects;
	markedForDelete;
}

Level::~Level()
{
	Destroy();
}

void Level::AddGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
}

void Level::RemoveGameObject(GameObject* gameObject)
{
	markedForDelete.push_back(gameObject);
}

void Level::Tick()
{
	Update();
	FixedUpdate();
	LateUpdate();
	DeleteMarked();
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

void Level::LateFixedUpdate()
{
	for (GameObject* gameObject : gameObjects)
		gameObject->LateFixedUpdate();
}

void Level::Destroy()
{
	for (GameObject* gameObject : gameObjects)
		delete gameObject;
}

void Level::DeleteMarked()
{
	if (markedForDelete.size() > 0)
	{
		for (GameObject* go : markedForDelete)
		{
			gameObjects.remove(go);
			delete go;
		}
		markedForDelete.clear();
	}
}
