/*
#pragma once
class Matrix4x4
{
public:
	int rows;
	int cols;
	int** matrix;

	Matrix4x4(int rows, int cols) {

	};
	Matrix4x4();
	~Matrix4x4();
	int getRows();
	int getCols();

	Matrix4x4(float data[4][4]);

	void print() const;

	void LoadIdentity();

	Matrix4x4 operator+(const Matrix4x4& other) const;

	Matrix4x4 operator-(const Matrix4x4& other) const;

	Matrix4x4 operator*(const Matrix4x4& other) const;

	Matrix4x4 operator*(const float& other) const;

	void setMatrixAsInsversionOfGivenMatrix(const Matrix4x4& other);

	Matrix4x4 getInversionOfMatrix() const;

	void invertMatrix();

	void SetRotationX(const double angle);

	void SetRotationY(const double angle);

	void SetRotationZ(const double angle);

};
*/