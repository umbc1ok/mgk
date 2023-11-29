#include "Vector.h"

#include <iostream>
#include <cmath>
#include "Matrix.h"

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {};


Vector::Vector()
{
}

float Vector::length()
{
	return sqrt(x * x + y * y + z * z);
}

void Vector::add(Vector v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
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

float Vector::dot(Vector v)
{
	return this->x * v.x + this->y * v.y + this->z * v.z;
}

float Vector::findAngle(Vector v)
{
	float dot = this->dot(v);
	float len1 = this->length();
	float len2 = v.length();
	float angle = acos(dot / (len1 * len2));
	return angle;
}

Vector Vector::normalize()
{
	float len = this->length();
	Vector normalised;
	if (len != 0) {
		this->div(len);
		normalised = *this;
	}
	else
	{
		std::cout << "dividing by 0!" << std::endl;
	}

	return normalised;
}

Vector Vector::cross(Vector v)
{
	Vector cross;
	cross.x = this->y * v.z - this->z * v.y;
	cross.y = this->z * v.x - this->x * v.z;
	cross.z = this->x * v.y - this->y * v.x;
	return cross;

}

bool Vector::operator==(Vector other)
{
	return this->x == other.x && this->y == other.y && this->z == other.z;
}

Vector Vector::operator+(Vector v)
{
	Vector result = Vector(this->x + v.x, this->y + v.y, this->z + v.z);
	return result;
}

Vector Vector::operator-(Vector other)
{
	Vector result = Vector(this->x - other.x, this->y - other.y, this->z - other.z);
	return result;
}

Vector Vector::operator*(float a)
{
	Vector result = Vector(this->x * a, this->y * a, this->z * a);
	return result;
}

Vector Vector::operator/(float a)
{
	Vector result = Vector(this->x / a, this->y / a, this->z / a);
	return result;
}

Vector::~Vector()
{
}