#include "Vector.h"
#include "Line.h"
#include <cmath>
#include "Plane.h"
#include "LineSegment.h"
#include "Sphere.h"
#include <utility>
#pragma once


// INTERSECTIONS:
// Line + plane - DONE
// Line + line - DONE
// Line segment + line segment - DONE
// Plane + plane - DONE

Vector intersection(Line l1, Line l2)
{
	Vector p1 = l1.p;
	Vector p2 = l2.p;
	Vector v1 = l1.v;
	Vector v2 = l2.v;

	float t1 = (((p2 - p1).cross(v2)).dot(v1.cross(v2))) / std::pow((v1.cross(v2)).magnitude(), 2);
	float t2 = -(((p2 - p1).cross(v1)).dot(v2.cross(v1))) / std::pow((v2.cross(v1)).magnitude(), 2);

	if (p1 + v1 * t1 == p2 + v2 * t2)
		return p1 + v1 * t1;

	return Vector(NAN, NAN, NAN);
}



Vector intersection(Line l, Plane p)
{
	Vector n = p.normal;
	Vector p0 = l.p;
	Vector q0 = p.p;
	Vector v = l.v;

	float t = -n.dot(p0 - q0) / n.dot(v);
	Vector P = p0 + v * t;

	if (n.dot(P - q0) == 0)
		return P;

	return Vector(NAN, NAN, NAN);
}
Vector intersection(LineSegment l1, LineSegment l2)
{
	Vector p1 = l1.p;
	Vector p2 = l2.p;
	Vector v1 = l1.v;
	Vector v2 = l2.v;

	float t1 = (((p2 - p1).cross(v2)).dot(v1.cross(v2))) / std::pow((v1.cross(v2)).magnitude(), 2);
	float t2 = -(((p2 - p1).cross(v1)).dot(v2.cross(v1))) / std::pow((v2.cross(v1)).magnitude(), 2);

	if (t1 < 0 || t1 > 1 || t2 < 0 || t2 > 1)
		return Vector(NAN, NAN, NAN);

	if (p1 + v1 * t1 == p2 + v2 * t2)
		return p1 + v1 * t1;

	return Vector(NAN, NAN, NAN);
}

Line intersection(Plane p1, Plane p2)
{
	if (p1.normal.angle(p2.normal) == 0 && p1.p == p2.p) // If planes are equal this returns example vector from them
		return Line(p1.p, (Vector(0, 1, 0).cross(p1.normal)));

	Vector direction = p1.normal.cross(p2.normal);
	float det = direction.magnitude() * direction.magnitude();

	if (det == 0.0f)
		return Line({ 0,0,0 }, Vector(NAN, NAN, NAN));

	Vector point = ((direction.cross(p2.normal) * p1.d) + (p1.normal.cross(direction) * p2.d)) / det;

	return Line(point, direction);
}

std::pair<Vector, Vector> intersection(Sphere s, Line l)
{
	float a = l.v.dot(l.v);
	float b = 2.0f * l.v.dot((l.p - s.point));
	float c = (l.p - s.point).dot(l.p - s.point) - (s.radius * s.radius);

	float delta = b * b - 4.0f * a * c;

	if (delta < 0)
		return std::make_pair(Vector(NAN, NAN, NAN), Vector(NAN, NAN, NAN));

	float t1 = (-b + sqrt(delta)) / (2.0f * a);
	float t2 = (-b - sqrt(delta)) / (2.0f * a);

	Vector p1 = l.p + l.v * t1;
	Vector p2 = l.p + l.v * t2;

	return std::make_pair<Vector, Vector>(Vector(p1), Vector(p2));
}


float angleBetween(Plane p1, Plane p2)
{
	return p1.normal.angle(p2.normal);
}

float angleBetween(Line l1, Line l2)
{
	return l1.v.angle(l2.v);
}
float angleBetween(Line l, Plane p)
{
	 Vector n = p.normal;
	 Vector v = l.v;
	 float angleDeg = v.angle(n) * 180 / M_PI;
	float result = 0;

	if (angleDeg > 90)
		result = angleDeg - 90;
	else
		result = 90 - angleDeg;

	return result;
}

