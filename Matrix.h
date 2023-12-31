#pragma once
class Matrix
{
public:
	int rows;
	int cols;
	float** matrix;

	Matrix();
	Matrix(int rows, int cols);

	void Print() const;

	void Add(Matrix& other);

	void Subtract(Matrix& other);

	void Multiply(float factor);

	Matrix Multiply(Matrix& other);

	float Determinant();

	void Transpose();
	static Matrix getTransposeOfMatrix(Matrix m) ;
	static Matrix getInverseOfMatrix( Matrix m) ;

	float cofactorAt(unsigned int row, unsigned int col) const;

	
	void Print();

};