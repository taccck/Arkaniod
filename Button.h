#pragma once
#include "GameObject.h"
#include "GamerTools.h"
#include <string>

class Button :
    public Component
{
private:
    Button* self = this;
    Vector2<float> size;
    GameObject* gameObject;
    int state;

public:
    std::string name;

    void (*OnClick)(Button*) = nullptr;

    Button(Vector2<float>, GameObject*, std::string);

    void Update() override;
    void LateUpdate() override;
}; 