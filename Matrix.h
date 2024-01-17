#pragma once
#include "Vector.h"
class Matrix
{
public:
	int rows;
	int cols;
	float** matrix;

	Matrix();
	Matrix(int rows, int cols);
	void setUp();

	void Print() const;

	void Add(Matrix& other);

	void Subtract(Matrix& other);

	void Multiply(float factor);

	Matrix Multiply(Matrix& other);

	Vector operator*(Vector& other);

	float Determinant();

	void Transpose();
	static Matrix getTransposeOfMatrix(Matrix m) ;
	static Matrix getInverseOfMatrix( Matrix m) ;
	Matrix getRotationPart();

	float cofactorAt(unsigned int row, unsigned int col) const;

	Matrix extendMatrix(const Matrix& other);

	
	void Print();

};