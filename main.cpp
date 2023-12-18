#define _USE_MATH_DEFINES
#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "CommonMatricies.h"
#include "Quaternion.h"



int main() {

	Quaternion q1(1, 2, 3, 4);
	Quaternion q2(5, 6, 7, 8);

	std::cout << "Q1 \n";
	q1.Print();
	std::cout << "Q2 \n";
	q2.Print();	
	
	std::cout << "Add \n";
	Quaternion q3 = q1 + q2;
	q3.Print();

	std::cout << "\n Subtract \n";
	Quaternion q4 = q1 - q2;
	q4.Print();

	std::cout << "\n Multiply \n";
	Quaternion q5 = q1 * q2;
	q5.Print();

	std::cout << "\n Multiply by scalar \n";
	Quaternion q6 = q1 * 2;
	q6.Print();

	std::cout << "\n Divide \n";
	Quaternion q7 = q1 / q2;
	q7.Print();

	std::cout << "\n Rotate \n punkt [-1,-1,-1]obroc o 270° wokoc osi x \n";
	Vector v1(-1, -1, -1);
	Vector axis(1, 0, 0);
	float angle = 270 * M_PI/180;
	Vector v2 = q1.rotate(v1, axis, angle);
	v2.Print();

	std::cout << "\n No commutativity of multiplication q1 and q2 \n";
	Quaternion result1 = q1 * q2;
	Quaternion result2 = q2 * q1 ;

	std::cout << "\n q1 * q2: \n";
	result1.Print();
	std::cout << "\n q2 * q1: \n";
	result2.Print();
	std::cout << "Are (q1 * q2) and (q2 * q1) equal? " << (result1 == result2) << std::endl;





	std::cout << "\n";
}

