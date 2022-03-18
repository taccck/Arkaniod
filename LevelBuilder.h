#pragma once
#include "Level.h"
#include <vector>
#include <string>

class LevelBuilder :
    public Component
{
private:
    bool placedThisPress = true; //makes sure you only place one block per click

public:
    bool pressedButtonThisFrame = false; //don't place a block when you press a button
    std::string placedBlocks; //serialized values of all placed blocks
    int placingHp = 1;
    void Update() override;

};