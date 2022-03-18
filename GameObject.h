#pragma once
#include "Component.h"
#include "Transform.h"

class GameObject
{
private:
	std::vector<Component*> components;
	void Destroy();

public:
	Transform* transform;

	GameObject();
	~GameObject();

	template<typename T>
	T* GetComponent()
	{
		for (Component* component : components)
		{
			T* componentAsT = dynamic_cast<T*>(component);
			if (componentAsT != NULL) return componentAsT;
		}
	}
	void AddComponent(Component* component);

	void Start();
	void Update();
	void FixedUpdate();
	void LateUpdate();
};