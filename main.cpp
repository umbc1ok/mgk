
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

	Matrix czteryDe(4, 4);
	czteryDe.matrix[0][0] = 1;
	czteryDe.matrix[0][1] = 2;
	czteryDe.matrix[0][2] = 4;
	czteryDe.matrix[0][3] = 4;

	czteryDe.matrix[1][0] = 5;
	czteryDe.matrix[1][1] = 1;
	czteryDe.matrix[1][2] = 3;
	czteryDe.matrix[1][3] = 1;

	czteryDe.matrix[2][0] = 1;
	czteryDe.matrix[2][1] = 1;
	czteryDe.matrix[2][2] = 3;
	czteryDe.matrix[2][3] = 7;

	czteryDe.matrix[3][0] = 5;
	czteryDe.matrix[3][1] = 2;
	czteryDe.matrix[3][2] = 3;
	czteryDe.matrix[3][3] = 1;

	std::cout << "Matrix:" << std::endl;
	czteryDe.Print();
	std::cout << "Determinant:" << czteryDe.Determinant() << std::endl;
	std::cout << "Inversed:" << std::endl;
	Matrix::getInverseOfMatrix(czteryDe).Print();






	std::cout << "Determinant:" << zz.Determinant() << std::endl;
	std::cout << "transpose test:" << std::endl;
	zz.Print();
	std::cout << std::endl;
	zz.setMatrixAsTranspose(zz);
	zz.Print();
	std::cout << std::endl;



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

	Matrix zz2(3, 3);
	zz2.getInverseOfMatrix(zz);
	zz2.Multiply(zz);
	std::cout << "if all are ones, then it's ok" << std::endl;
	zz2.Print();
	std::cout << std::endl;


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

	//TRANSLACJE
	/*std::cout << "TRANSPOSE\n AAA" << std::endl;
	Matrix aaa(2, 5);
	Matrix bbb(2, 5);
	aaa.matrix[0][0] = 1;
	aaa.matrix[0][1] = 2;
	aaa.matrix[0][2] = 4;
	aaa.matrix[0][3] = 5;
	aaa.matrix[0][4] = 6;
	aaa.matrix[1][0] = 6;
	aaa.matrix[1][1] = 2;
	aaa.matrix[1][2] = 3;
	aaa.matrix[1][3] = 4;
	aaa.matrix[1][4] = 5;

	
	std::cout << "Macierz \n";
	aaa.Print();
	bbb.setMatrixAsTranspose(aaa);
	std::cout << "MAcierz transponowana\n";
	bbb.Print();*/
	


	//MACIRZ ODWROTNA
std::cout << "INVERSE\n BBB" << std::endl;
	Matrix oo(3, 3);
	Matrix ss(3, 3);
	oo.matrix[0][0] = 2;
	oo.matrix[0][1] = 5;
	oo.matrix[0][2] = 7;

	oo.matrix[1][0] = 6;
	oo.matrix[1][1] = 3;
	oo.matrix[1][2] = 4;

	oo.matrix[2][0] = 5;
	oo.matrix[2][1] = -2;
	oo.matrix[2][2] = -3;


	/*oo.matrix[0][0] = -2;
	oo.matrix[0][1] = 3;

	oo.matrix[1][0] = -4;
	oo.matrix[1][1] = 7;*/



	oo.Print();
	std::cout << "macierz po inwersji \n";

	ss = oo.getInverseOfMatrix(oo);

	ss.Print();
	std::cout << "\n";
}

