#pragma once
class Matrix
{
public:
	int rows;
	int cols;
	float** matrix;

	Matrix();
	Matrix(int rows, int cols);

	void Add(Matrix& other);

	void Subtract(Matrix& other);

	void Multiply(float factor);

	Matrix Multiply(Matrix& other);

	float Determinant();



	// transpose function (for all dimensions)

	void setMatrixAsTranspose(Matrix& m);
	Matrix getTransposeOfMatrix();
	Matrix getInverseOfMatrix(Matrix& m) const;

	// inversion function (for all dimensions), although not all matrices are invertible


	// scaling functions for vectors

	// translation matrices for vectors

};