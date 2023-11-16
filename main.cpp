
#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "CommonMatricies.h"



int main() {


	Matrix a(4, 1);
	a.matrix[0][0] = 1;
	a.matrix[3][0] = 0;
	Matrix b = RotationY(90);
	Matrix result = b.Multiply(a);
	result.Print();
	return 0;




	/*
	// addition commutativity
	Vector v1(1, 2, 3);
	Vector v2(3, 4, 5);
	Vector v3(1, 2, 3);
	Vector v4(3, 4, 5);

	v1.add(v2);
	v3.add(v4);
	if(v1==v3){
		std::cout << "cool" << std::endl;
	}
	else {
		std::cout << "not cool" << std::endl;
	}


	// find the angle between two vectors
	Vector v5(0, 3, 0);
	Vector v6(5, 5, 0);
	std::cout << v5.findAngle(v6) << " rad" << std::endl;
	std::cout << v5.findAngle(v6) * 180.0 / M_PI << " stopni" << std::endl;


	// znajdywanie wektora prostopadlego
	Vector v7(4, 5, 1);
	Vector v8(4, 1, 3);

    // find a vector perpendicular to v7 and v8
	Vector v9 = v7.cross(v8);
	std::cout << v9.x << v9.y << v9.z << std::endl;

	// normalize a vector
	Vector v10(1, 2, 3);
	Vector v11 = v10.normalize();
	std::cout << v11.x << " " << v11.y  << " " << v11.z << std::endl;

	*/


	// sprawdzenie operacji na macierzach
	Matrix m1(3, 3);
	Matrix m2(3, 3);
	m1.matrix[0][0] = 1;
	m1.matrix[0][1] = 2;
	m1.matrix[0][2] = 3;
	m1.matrix[1][0] = 4;
	m1.matrix[1][1] = 5;
	m1.matrix[1][2] = 6;
	m1.matrix[2][0] = 7;
	m1.matrix[2][1] = 8;
	m1.matrix[2][2] = 9;

	m2.matrix[0][0] = 1;
	m2.matrix[0][1] = 2;
	m2.matrix[0][2] = 3;
	m2.matrix[1][0] = 4;
	m2.matrix[1][1] = 5;
	m2.matrix[1][2] = 6;
	m2.matrix[2][0] = 7;
	m2.matrix[2][1] = 8;
	m2.matrix[2][2] = 9;

	m1.Subtract(m2);
	
	m1.Print();



}

