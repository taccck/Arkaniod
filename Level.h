#pragma once
#include "GameObject.h"
#include <list>

class Level
{
private:
	std::list<GameObject*> gameObjects;
	std::vector<GameObject*> gameObjectsToDelete;
	Level* self = this;

	void Update();
	void FixedUpdate();
	void LateUpdate();
	void Destroy();
	void DeleteMarked();
	void LoadNewLevel();

public:
	Level();

	void AddGameObject(GameObject* gameObject);
	void RemoveGameObject(GameObject* gameObject);
	void NewLevel(Level* lvl);

	void Start();
	void Tick();
};

extern Level* currLevel;