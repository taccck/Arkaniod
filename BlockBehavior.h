#pragma once
#include <string>
#include "Level.h"
#include "BoxCollider.h"

class BlockBehavior :
    public Component
{
private:
    GameObject* gameObject;

public:
    int hp;
    BlockBehavior(BoxCollider*, GameObject*, int);
    std::string Serialize();
};