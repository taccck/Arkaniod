#include "BlockBehavior.h"

void TakeDmg(GameObject* go, GameObject* collided, Vector2<float> norm)
{
	BlockBehavior* self = go->GetComponent<BlockBehavior>();
	self->hp--;
	go->transform->SetScale({ (float)self->hp, self->hp / 2.f });
	if (self->hp <= 0)
	{
		currLevel->RemoveGameObject(go);
	}
}

BlockBehavior::BlockBehavior(BoxCollider* box, GameObject* go, int startHp)
{
	hp = startHp;
	gameObject = go;
	go->transform->SetScale({ (float)hp, hp / 2.f });
	box->OnCollision = TakeDmg;
}

std::string BlockBehavior::Serialize()
{
	Vector2<float> pos = gameObject->transform->GetPosition();
	std::string s{};
	s += hp + 48;
	s += ',';
	s += std::to_string(pos.x);
	s += ',';
	s += std::to_string(pos.y);
	s += ',';
	s += '\n';
	return s;
}
