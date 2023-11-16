
#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "CommonMatricies.h"



int main() {


	Matrix zz(3, 3);
	zz.matrix[0][0] = 1;
	zz.matrix[0][1] = 2;
	zz.matrix[0][2] = 4;

	zz.matrix[1][0] = 5;
	zz.matrix[1][1] = 1;
	zz.matrix[1][2] = 3;

	zz.matrix[2][0] = 1;
	zz.matrix[2][1] = 1;
	zz.matrix[2][2] = 3;

	std::cout << "Add itself:" << std::endl;
	zz.Print();
	std::cout << "\n";

	zz.Add(zz);

	zz.Print();
	std::cout << "\n";


	std::cout << "Multiply x2:" << std::endl;
	zz.Print();
	std::cout << "\n";

	zz.Multiply(2);

	zz.Print();
	std::cout << "\n";



	std::cout << "Subtract itself" << std::endl;
	zz.Print();
	std::cout << "\n";

	zz.Subtract(zz);

	zz.Print();
	std::cout << "\n";








	// ROTATION TEST
	Matrix a(4, 1);
	a.matrix[0][0] = 1;
	a.matrix[3][0] = 0;
	Matrix b = RotationY(90);
	Matrix result = b.Multiply(a);
	result.Print();





	// PRZEMIENNOSC MNOZENIA MACIERZY
	Matrix aa(2, 2);
	aa.matrix[0][0] = 1;
	aa.matrix[0][1] = 2;
	aa.matrix[1][0] = 6;
	aa.matrix[1][1] = 2;
	Matrix bb(2, 2);
	bb.matrix[0][0] = 3;
	bb.matrix[0][1] = 7;
	bb.matrix[1][0] = 1;
	bb.matrix[1][1] = 3;

	Matrix cc = aa.Multiply(bb);
	Matrix dd = bb.Multiply(aa);

	std::cout << "CC\n";
	cc.Print();
	std::cout << "DD\n";
	dd.Print();




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





}

