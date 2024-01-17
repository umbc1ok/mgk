#pragma once
#include "Vector.h"
#include "Plane.h"

class Plane;

class Line
{
public:
	Line(const Vector& p, const Vector& v)
		: p(p),
		v(v)
	{
	}

	Vector p = Vector(0, 0, 0);
	Vector v = Vector(0, 0, 0);

	Vector IntersectionWithPlane(Plane plane)
	{
		float ts = plane.a * (v.x) + plane.b * (v.y) + plane.c * (v.z);
		float values = -plane.d - (plane.a * (p.x) + plane.b * (p.y) + plane.c * (p.z));
		float t = values / ts;

		return Vector(p.x + v.x * t, p.y + v.y * t, p.z + v.z * t);
	}
};