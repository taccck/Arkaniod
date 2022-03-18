#include "GameObject.h"

GameObject::GameObject()
{
	transform = new Transform();
}

GameObject::~GameObject()
{
	Destroy();
}

void GameObject::AddComponent(Component* component)
{
	components.push_back(component);
}

void GameObject::Update()
{
	for (Component* component : components)
		component->Update();
}

void GameObject::Start()
{
	for (Component* component : components)
		component->Start();
}

void GameObject::FixedUpdate()
{
	for (Component* component : components)
		component->FixedUpdate();
}

void GameObject::LateUpdate()
{
	for (Component* component : components)
		component->LateUpdate();
}

void GameObject::Destroy()
{
	for (Component* component : components)
	{
		component->Destroy();
		delete component;
	}
	delete transform;
}