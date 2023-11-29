#pragma once
#include "Vector.h"
class Quaternion {
public:
	float x;
	float y;
	float z;
	float w;

	Quaternion();
	Quaternion(float x, float y, float z, float w);

	void Print() const;



	Quaternion operator+(Quaternion& other);
	Quaternion operator-(Quaternion& other);
	Quaternion operator*(float a);
	Quaternion operator*(Quaternion& other);
	Quaternion operator/(Quaternion& other);

	bool operator==(const Quaternion& q) const;

	//angle in radians
	Vector rotate(const Vector& point,  Vector& axis, float angle) const;
};
