#include "Vector.h"
#include <iostream>


int main() {


	// przemiennosc dodawania
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


	// obliczanie kata pomiedzy wektorami
	Vector v5(0, 3, 0);
	Vector v6(5, 5, 0);
	std::cout << v5.findAngle(v6) << std::endl;


	// znajdywanie wektora prostopadlego
	Vector v7(4, 5, 1);
	Vector v8(4, 1, 3);



	Vector v9(1, 2, 3);

	Vector v10 = v9.normalize();

	std::cout << v10.x << v10.y << v10.z << std::endl;


}

