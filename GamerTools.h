#pragma once
#include <cmath>

extern float deltaTime;
extern const float fixedDeltaTime;
void UpdateDeltaTime();

template<typename T>
struct Vector2
{
public:
	T x;
	T y;

	Vector2() {};
	Vector2(T _x, T _y)
	{
		x = _x;
		y = _y;
	}

	void Normalize()
	{
		float mag = Vector2<T>::Magnitude({ x,y });
		x /= mag;
		y /= mag;
	}

	Vector2<T> Normalized()
	{
		Vector2 norm = { x,y };
		norm.Normalize();
		return norm;
	}

	void operator*=(float value)
	{
		x *= value;
		y *= value;
	}

	void operator/=(float value)
	{
		x /= value;
		y /= value;
	}

	static float Magnitude(Vector2<T> vector)
	{
		return sqrt(pow(vector.x, 2) + pow(vector.y, 2));
	}

	static float Distance(Vector2<T> v1, Vector2<T> v2)
	{
		Vector2<T> relativePosition = { v2.x - v1.x, v2.y - v1.y };
		return sqrt(pow(relativePosition.x, 2) + pow(relativePosition.y, 2));
	}
};

struct Line
{
	float slope{};
	float yIntercept{};
	float xIntercept{};
	bool vertical{};
	bool horizontal{};
	Vector2<float> points[2]{};

	Line() {}

	Line(Vector2<float>& a, Vector2<float>& b)
	{
		points[0] = a;
		points[1] = b;
		float deltaX = abs(b.x - a.x);
		float deltaY = abs(b.y - a.y);

		if (deltaX < 0.01f)
		{
			xIntercept = b.x;
			vertical = true;
			return;
		}
		if (deltaY < 0.01f)
		{
			yIntercept = b.y;
			horizontal = true;
			return;
		}
		slope = (b.y - a.y) / (b.x - a.x);
		yIntercept = -1 * (slope * a.x - a.y);
	}

	float GetY(float x)
	{
		if (vertical) return 0;
		return slope * x + yIntercept;
	}
	float GetX(float y)
	{
		if (horizontal) return 0;
		return (yIntercept - y) / slope * -1;
	}

	Line Perpendicular(Vector2<float>& a)
	{
		Line perp;
		if (horizontal)
		{
			perp.vertical = true;
			perp.xIntercept = a.x;
			return perp;
		}
		if (vertical)
		{
			perp.horizontal = true;
			perp.yIntercept = a.y;
			return perp;
		}

		perp.slope = slope * -1;
		yIntercept = -1 * (perp.slope * a.x - a.y);
		return perp;
	}

	bool IntersectBetween(Vector2<float>& intersectPoint)
	{
		if (abs(intersectPoint.x - 6969.F) < 1.F) return false;
		if (abs(intersectPoint.y - 6969.F) < 1.F) return false;

		if (horizontal)
		{
			bool zeroSmallerThanOne = points[0].x < points[1].x;
			float min = zeroSmallerThanOne ? points[0].x : points[1].x;
			float max = zeroSmallerThanOne ? points[1].x : points[0].x;
			return intersectPoint.x >= min && intersectPoint.x <= max;
		}
		bool zeroSmallerThanOne = points[0].y < points[1].y;
		float min = zeroSmallerThanOne ? points[0].y : points[1].y;
		float max = zeroSmallerThanOne ? points[1].y : points[0].y;
		return intersectPoint.y >= min && intersectPoint.y <= max;
	}

	static Vector2<float> PointOfIntersection(Line& a, Line& b)
	{
		if (a.vertical && b.vertical) //parallel lines don't intersect
			return { 6969.F, 6969.F };
		if (a.horizontal && b.horizontal)
			return { 6969.F, 6969.F };

		if (a.vertical && b.horizontal) //TODO same y value always
			return { a.xIntercept, b.yIntercept };
		if (b.vertical && a.horizontal)
			return { b.xIntercept, a.yIntercept };

		if (a.vertical)
			return { a.xIntercept, b.GetY(a.xIntercept) };
		if (a.horizontal)
			return { b.GetX(a.yIntercept), a.yIntercept };
		if (b.vertical)
			return { b.xIntercept, a.GetY(b.xIntercept) };
		if (b.horizontal)
			return { a.GetX(b.yIntercept), b.yIntercept };

		if (a.slope == b.slope) //parallel lines don't intersect
			return { 6969.F, 6969.F };

		Vector2<float> p{};
		float totSlope = a.slope - b.slope;
		float totYIntercept = a.yIntercept - b.yIntercept;
		p.x = totYIntercept / totSlope;
		p.y = a.GetY(p.x);
		return p;
	}
};