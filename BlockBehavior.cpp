#include "BlockBehavior.h"

void TakeDmg(GameObject* go, Vector2<float> norm)
{
	BlockBehavior* self = go->GetComponent<BlockBehavior>();
	self->hp--;
	go->transform->SetScale({ (float)self->hp, self->hp / 2.f });
	if (self->hp <= 0)
	{
		currLevel->RemoveGameObject(go);
	}
}

BlockBehavior::BlockBehavior(BoxCollider* box, int startHp, GameObject* go)
{
	hp = startHp;
	go->transform->SetScale({(float)hp, hp / 2.f});
	box->OnCollision = TakeDmg;
}