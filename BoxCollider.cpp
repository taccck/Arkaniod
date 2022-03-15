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

	lines.clear();
	Line topLine = Line(corners[3], corners[0]);
	lines.push_back(topLine);
	Line rightLine = Line(corners[0], corners[1]);
	lines.push_back(rightLine);
	Line botLine = Line(corners[1], corners[2]);
	lines.push_back(botLine);
	Line leftLine = Line(corners[2], corners[3]);
	lines.push_back(leftLine);
}

bool BoxCollider::CheckCollision()
{
	for (BoxCollider* box : allColliders)
	{
		if (box == self) continue;

		Line collidedWith;
		float longestDist = 0.f;
		Vector2<float> boxPos = box->corners[4];

		for (Line otherLine : box->lines)
		{
			for (Line thisLine : lines)
			{
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
				OnCollision(gameObject, box->GetNormal(collidedWith, boxPos));
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
}

BoxCollider::~BoxCollider()
{
	Destroy();
}

Vector2<float>* BoxCollider::Sweep()
{
	UpdateCorners();

	for (BoxCollider* box : allColliders)
	{
		if (box == self) continue;

		Line* collidedWith = nullptr;
		float longestDist = 0.f;
		Vector2<float> boxPos = box->corners[4];

		for (Line otherLine : box->lines)
		{
			for (Line thisLine : lines)
			{
				Vector2<float> intersect = Line::PointOfIntersection(thisLine, otherLine);
				if (thisLine.IntersectBetween(intersect) && otherLine.IntersectBetween(intersect))
				{
					float dist = Vector2<float>::Distance(corners[4], intersect);
					if (dist > longestDist)
						collidedWith = &otherLine;
				}
			}
		}

		if (collidedWith != nullptr)
		{
			Vector2<float> normal = box->GetNormal(*collidedWith, boxPos);
			if (OnCollision != nullptr)
				OnCollision(box->gameObject, normal);
			Vector2<float> boxPos = { box->corners[4] };
			Vector2<float> relativePos = corners[4]; //wrong??
			relativePos = { relativePos.x - boxPos.x, relativePos.y - boxPos.y };
			relativePos.Normalize();
			Vector2<float> perp = { -normal.y, normal.x };
			float scalarProjection = relativePos.x * perp.x + relativePos.y * perp.y;
			if (scalarProjection < 0)
			{
				perp = { normal.y, -normal.x };
				scalarProjection = relativePos.x * perp.x + relativePos.y * perp.y;
			}
			return new Vector2<float>(perp.x * scalarProjection, perp.y * scalarProjection);
		}
	}
	return 0;
}

void BoxCollider::Start()
{
}

void BoxCollider::Update()
{
}

void BoxCollider::FixedUpdate()
{
	if (!updatedThisFrame)
	{
		for (BoxCollider* box : allColliders)
			box->UpdateCorners();
		updatedThisFrame = true;
	}

	if (!physicBody)
		CheckCollision();
}

void BoxCollider::LateUpdate()
{
	updatedThisFrame = false;
}

void BoxCollider::LateFixedUpdate()
{
}

void BoxCollider::Destroy()
{
	allColliders.remove(self);
	lines.clear();
	lines.shrink_to_fit();
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