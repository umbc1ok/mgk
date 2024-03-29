#pragma once
#include <string>
class Vector
{

public:
	float x;
	float y;
	float z;

	Vector(float x, float y, float z);
	Vector();

	float length();

	void add(Vector v);

	void subb(Vector v);

	void mul(float a);

	void div(float a);

	float findAngle(Vector v);

	Vector normalize();

	//iloczyn skalarny
	float dot(Vector v);

	//iloczyn wektorowy

	Vector cross(Vector v);

	bool operator==(Vector other);
	Vector operator+(Vector other);
	Vector operator-(Vector other);
	Vector& operator-(const Vector& other) const;
	Vector operator*(float a);
	Vector operator*(const float a) const;
	Vector operator*(Vector& other);
	Vector operator/(float a);

	void Print() const;

	float magnitude() const;

	float angle(Vector v);

	std::string ToString();

	static Vector invalid();

	~Vector();
};