#pragma once
#include "GameObject.h"
#include <list>

class Level
{
private:
	std::list<GameObject*> gameObjects;
	std::vector<GameObject*> markedForDelete;
	Level* self = this;

	void Update();
	void FixedUpdate();
	void LateUpdate();
	void LateFixedUpdate();
	void Destroy();
	void DeleteMarked();

public:
	Level();
	~Level();

	void AddGameObject(GameObject* gameObject);
	void RemoveGameObject(GameObject* gameObject);

	void Start();
	void Tick();
};

extern Level* currLevel;