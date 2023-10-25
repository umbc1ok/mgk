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
	this->x += v.x;
	this->y += v.y;
	this->z += v.z
}

void Vector::subb(Vector v)
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
}

void Vector::mul(float a)
{
	this->x *= a;
	this->y *= a;
	this->z *= a;
}

void Vector::div(float a)
{
	this->x /= a;
	this->y /= a;
	this->z /= a;
}

flaot Vector::dot(Vector v)
{
	return flaot();
}

flaot Vector::findAngle(Vector v)
{
	return flaot();
}

Vector Vector::normalize()
{
	float len = v.length();
	Vector normalised;
	if (len != 0) {
		normalised = this->div(len);
	}
	else
	{
		std::count << "dividing by 0!" << std::endl;
	}

	return normalised;
}

Vector Vector::cross(Vector v)
{
	return Vector();
}

Vector::~Vector()
{
}
