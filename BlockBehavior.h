#pragma once
#include "Level.h"
#include "BoxCollider.h"

class BlockBehavior :
    public Component
{
public:
    int hp;
    BlockBehavior(BoxCollider*, int, GameObject*);
};