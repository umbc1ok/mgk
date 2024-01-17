#pragma once
#pragma once
#include "Vector.h"

class Plane
{
	public:
	float a, b, c, d;
	Plane(const Vector& p, const Vector& normal);
	Plane(float a, float b, float c, float d);
	Plane(Vector A, Vector B, Vector C, Vector D);
	Plane() {};

	Vector p = Vector(0, 0, 0);
	Vector normal = Vector(0, 0, 0);

};