#pragma once
class Matrix
{
public:
	int rows;
	int cols;
	float** matrix;


	Matrix(int rows, int cols);

	void Add(Matrix& other);

	void Subtract(Matrix& other);

	void Multiply(float factor);

	Matrix Multiply(Matrix& other);

	float Determinant();

	void Print();

};