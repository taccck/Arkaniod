#pragma once
#include "GameObject.h"
#include "GamerTools.h"


class MovingBody :
	public Component
{
public:
	GameObject* gameObject; // feedback: not sure I fully understand the design here. Moving body is derived from component which makes sense.
							// however game object is aggregated. To me it would make more sense to derive from the game object as well.
							// Assignemnt of any arbitrary gameObject to moving object is hard for me to grasp.
	Vector2<float> velocity;

	MovingBody(GameObject* go);

	void FixedUpdate() override;
};