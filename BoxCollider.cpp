#include "BoxCollider.h"

std::list<BoxCollider*> allColliders{};
bool updatedThisFrame{ false };

void BoxCollider::UpdateCorners()
{
	Vector2<float> scaledSize = gameObject->transform->GetScale();
	scaledSize.x *= size.x;
	scaledSize.y *= size.y;
	scaledSize.x /= 200.f;
	scaledSize.y /= 200.f;
	Vector2<float> pos = gameObject->transform->GetPosition();

	delete[] corners;
	corners = new Vector2<float>[5];
	corners[0] = Vector2<float>(pos.x + scaledSize.x, pos.y + scaledSize.y);
	corners[1] = Vector2<float>(pos.x + scaledSize.x, pos.y - scaledSize.y);
	corners[2] = Vector2<float>(pos.x - scaledSize.x, pos.y - scaledSize.y);
	corners[3] = Vector2<float>(pos.x - scaledSize.x, pos.y + scaledSize.y);
	corners[4] = pos;

	delete[] lines;
	lines = new Line[4];
	Line topLine = Line(corners[3], corners[0]);
	lines[0] = topLine;
	Line rightLine = Line(corners[0], corners[1]);
	lines[1] = rightLine;
	Line botLine = Line(corners[1], corners[2]);
	lines[2] = botLine;
	Line leftLine = Line(corners[2], corners[3]);
	lines[3] = leftLine;
}

bool BoxCollider::CheckCollision()
{
	for (BoxCollider* box : allColliders)
	{
		if (box == self) continue;

		Line collidedWith;
		float longestDist = 0.f;
		Vector2<float> boxPos = box->corners[4];

		for (size_t o = 0; o < 4; o++)
		{
			Line otherLine = box->lines[o];
			for (size_t t = 0; t < 4; t++)
			{
				Line thisLine = lines[t];
				Vector2<float> intersect = Line::PointOfIntersection(thisLine, otherLine);
				if (thisLine.IntersectBetween(intersect) && otherLine.IntersectBetween(intersect))
				{
					float dist = Vector2<float>::Distance(corners[4], intersect);
					if (dist > longestDist)
					{
						longestDist = dist;
						collidedWith = otherLine;
					}
				}
			}
		}

		if (longestDist > .1F)
		{
			if (OnCollision != nullptr)
				OnCollision(gameObject, box->gameObject, box->GetNormal(collidedWith, boxPos));
			if (!box->physicBody && box->OnCollision != nullptr)
				box->OnCollision(box->gameObject, gameObject, { 6969.f, 6969.f });
			return true;
		}
	}
	return false;
}

BoxCollider::BoxCollider(GameObject* go, Vector2<float> pixelSize)
{
	size = pixelSize;
	gameObject = go;
	allColliders.push_back(self);
	isColliding = false;
}

BoxCollider::~BoxCollider()
{
	Destroy();
}

void BoxCollider::FixedUpdate()
{
	if (!updatedThisFrame)
	{
		for (BoxCollider* box : allColliders)
			box->UpdateCorners();
		updatedThisFrame = true;
	}

	if (physicBody)
		isColliding = CheckCollision();
}

void BoxCollider::LateUpdate()
{
	updatedThisFrame = false;
}

void BoxCollider::Destroy()
{
	allColliders.remove(self);
	delete[] lines;
	delete[] corners;
}

Vector2<float> BoxCollider::GetNormal(Line& lineCollided, Vector2<float>& pos)
{
	Line normalLine = lineCollided.Perpendicular(pos);
	Vector2<float> normalDir = Line::PointOfIntersection(lineCollided, normalLine);
	Vector2<float> normal = { pos.x - normalDir.x, pos.y - normalDir.y };
	normal.Normalize();
	return normal;
}