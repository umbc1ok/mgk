#pragma once
#include "Vector.h"

struct Line
{
public:
	Line(const Vector& p, const Vector& v)
		: p(p),
		v(v)
	{
	}

	Vector p = Vector(0, 0, 0);
	Vector v = Vector(0, 0, 0);
};