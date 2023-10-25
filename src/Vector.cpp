#include "./lib/Vector.h"

#include <iostream>
#include <cmath>

Vector::Vector(float x, float y, float z)
	: x(x), y(y), z(z)
{
}


float Vector::lenght()
{
	return sqrt(x*x + y*y + z*z);
}

void Vector::add(Vector v)
{
	this.x += v.x;
	this.y += v.y;
	this z += v.z
}

void Vector::subb(Vector v)
{
	this.x -= v.x;
	this.y -= v.y;
	this.z -= v.z;
}

void Vector::mul(float a)
{
}

void Vector::div(float a)
{
}

flaot Vector::dot(Vector v)
{
	return flaot();
}

flaot Vector::findAngle(Vector v)
{
	return flaot();
}

Vector Vector::normalize(Vector v)
{
	return Vector();
}

Vector Vector::cross(Vector v)
{
	return Vector();
}

Vector::~Vector()
{
}
