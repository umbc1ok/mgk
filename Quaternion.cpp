#include "Quaternion.h"
#include <iostream>

Quaternion::Quaternion() {
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Quaternion::Quaternion(float x, float y, float z, float w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

void Quaternion::Print() const {
	std::cout << "x: " << x << " y: " << y << " z: " << z << " w: " << w << std::endl;
}	
Quaternion Quaternion::operator+(Quaternion& other) {
	Quaternion result;
	result.x = x + other.x;
	result.y = y + other.y;
	result.z = z + other.z;
	result.w = w + other.w;


	return result;


}

Quaternion Quaternion::operator-(Quaternion& other) {
	Quaternion result;
	result.x = x - other.x;
	result.y = y - other.y;
	result.z = z - other.z;
	result.w = w - other.w;


	return result;
}
// yyy idk czy to akurat jest potrzebne ale I guess tak
Quaternion Quaternion::operator*(float factor) {
	Quaternion result;
	result.x *= x * factor;
	result.y *= y * factor;
	result.z *= z * factor;
	result.w *= w * factor;

	return result;
}



Quaternion Quaternion::operator*(Quaternion& other) {

	Vector v1(x, y, z);
	Vector v2(other.x, other.y, other.z);
	float scalar = w * other.w - v1.dot(v2);
	Vector resultVector = v2*(w) + v1*(other.w) + v1.cross(v2);


	return Quaternion(resultVector.x, resultVector.y, resultVector.z, scalar);

	/*
	Quaternion result;
	result.w = w * other.w - x * other.x - y * other.y - z * other.z; // this is git
	result.x = w * other.x + x * other.w + y * other.z - z * other.y; // this is also git
	result.y = w * other.y - x * other.z + y * other.w + z * other.x; // this is also very git
	result.z = w * other.z + x * other.y - y * other.x + z * other.w; // this is also very very git
	return result;
	*/
}

Quaternion Quaternion::operator/(Quaternion& other) {
	Vector v1(x, y, z);
	Vector v2(other.x, other.y, other.z);

	if (other.w * other.w + v2.dot(v2) == 0) {
		std::cout << "Division by 0!" << std::endl;
	}
	float scalar = (w * other.w + v1.dot(v2)) / (other.w * other.w + v2.dot(v2));
	Vector resultVector = (v2 *(-w) + v1 * other.w - v1.cross(v2)) / (other.w * other.w + v2.dot(v2));

	return Quaternion(resultVector.x, resultVector.y, resultVector.z, scalar);

}



bool Quaternion::operator==(const Quaternion& q) const {
	return (x == q.x && y == q.y && z == q.z && w == q.w);
}

Vector Quaternion::rotate(const Vector& point, const Vector& axis, float angle) const {
	Quaternion result;
	float q_scalar = cos(angle / 2);
	//Vector q_vector = axis * sin(angle / 2);
	return Vector();
}