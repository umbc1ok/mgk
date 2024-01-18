#include "Plane.h"
#include "Utilities.h"
#define _USE_MATH_DEFINES // for C
#include <math.h>

Plane::Plane(const Vector& p, const Vector& normal)
{
	this->p = p;
	this->normal = normal;
}

Plane::Plane(float a, float b, float c, float d)
{
	this->normal = { a, b, c };
	this->d = d;
	p = { 0, 0, -d / c };

	if (floatNearlyEqual(this->normal.angle({ 0,0,1 }) * 180 / M_PI, 0))
		p = { 0, -d / b, 0 };
	if (floatNearlyEqual(this->normal.angle({ 0,1,0 }) * 180 / M_PI, 0))
		p = { -d / a, 0, 0 };
}

Plane::Plane(Vector A, Vector B, Vector C, Vector D)
{
    Vector v1 = B;
    v1.subb(A);
    Vector v2 = C;
    v2.subb(B);
    normal = v1.cross(v2);
    normal.mul(-1);
    Vector negativeNormal = normal;
    negativeNormal.mul(-1);
    a = normal.x;
    b = normal.y;
    c = normal.z;
    d = negativeNormal.dot(A);
}

