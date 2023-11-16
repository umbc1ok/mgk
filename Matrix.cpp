#pragma once

#include <iomanip>
#include "Matrix.h"
#include <iostream>

/*
v dodawanie
v odejmowanie
v mno¿enie przez skalar
v mno¿enie przez macierz
v macierz jednostkowa (jest w CommonMatricies.h)
v transponowanie
- macierz odwrotna
v > wyznacznik do 4x4
*/


Matrix::Matrix()
{
}

Matrix::Matrix(int rows, int cols)
{
	this->matrix = new float* [rows];

	// Allocate memory for each row
	for (int i = 0; i < rows; ++i) {
		this->matrix[i] = new float[cols];
	}
	
	this->rows = rows;
	this->cols = cols;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = 0;
		}
	}
};

void Matrix::Add(Matrix& other) {
	if (this->rows == other.rows && this->cols == other.cols)
	{
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->cols; j++) {
				this->matrix[i][j] += other.matrix[i][j];
			}
		}
	}
	else {
		std::cout << "Nie mozna dodac macierzy o roznych wymiarach" << std::endl;
	}
};
void Matrix::Subtract(Matrix& other) {
	if (this->rows == other.rows && this->cols == other.cols)
	{
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->cols; j++) {
				this->matrix[i][j] -= other.matrix[i][j];
			}
		}
	}
	else {
		std::cout << "Nie mozna dodac macierzy o roznych wymiarach" << std::endl;
	}
};

void Matrix::Multiply(float factor) {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			this->matrix[i][j] *= factor;
		}
	}
};
Matrix Matrix::Multiply(Matrix& other) {
	if (this->cols == other.rows)
	{
		Matrix result(this->rows, other.cols);
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < other.cols; j++) {
				for (int k = 0; k < this->cols; k++) {
					result.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
				}
			}
		}
		return result;
	}
	else {
		std::cout << "Nie mozna pomnozyc macierzy o roznych wymiarach" << std::endl;
		return Matrix();
	}
}
float Matrix::Determinant()
{
	if (this->cols == this->rows) {
		if (cols == 1) {
			return matrix[0][0];
		}
		else if (cols == 2) {
			return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
		}
		else if (cols == 3) {
			return matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[0][1] * matrix[1][0] * matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1];
		}
		else if (cols == 4) {

			float det = matrix[0][3] * matrix[1][2] * matrix[2][1] * matrix[3][0] - matrix[0][2] * matrix[1][3] * matrix[2][1] * matrix[3][0] -
				matrix[0][3] * matrix[1][1] * matrix[2][2] * matrix[3][0] + matrix[0][1] * matrix[1][3] * matrix[2][2] * matrix[3][0] +
				matrix[0][2] * matrix[1][1] * matrix[2][3] * matrix[3][0] - matrix[0][1] * matrix[1][2] * matrix[2][3] * matrix[3][0] -
				matrix[0][3] * matrix[1][2] * matrix[2][0] * matrix[3][1] + matrix[0][2] * matrix[1][3] * matrix[2][0] * matrix[3][1] +
				matrix[0][3] * matrix[1][0] * matrix[2][2] * matrix[3][1] - matrix[0][0] * matrix[1][3] * matrix[2][2] * matrix[3][1] -
				matrix[0][2] * matrix[1][0] * matrix[2][3] * matrix[3][1] + matrix[0][0] * matrix[1][2] * matrix[2][3] * matrix[3][1] +
				matrix[0][3] * matrix[1][1] * matrix[2][0] * matrix[3][2] - matrix[0][1] * matrix[1][3] * matrix[2][0] * matrix[3][2] -
				matrix[0][3] * matrix[1][0] * matrix[2][1] * matrix[3][2] + matrix[0][0] * matrix[1][3] * matrix[2][1] * matrix[3][2] +
				matrix[0][1] * matrix[1][0] * matrix[2][3] * matrix[3][2] - matrix[0][0] * matrix[1][1] * matrix[2][3] * matrix[3][2] -
				matrix[0][2] * matrix[1][1] * matrix[2][0] * matrix[3][3] + matrix[0][1] * matrix[1][2] * matrix[2][0] * matrix[3][3] +
				matrix[0][2] * matrix[1][0] * matrix[2][1] * matrix[3][3] - matrix[0][0] * matrix[1][2] * matrix[2][1] * matrix[3][3] -
				matrix[0][1] * matrix[1][0] * matrix[2][2] * matrix[3][3] + matrix[0][0] * matrix[1][1] * matrix[2][2] * matrix[3][3];
			return det;
		}
		else {
			std::cout << "Nie potrafimy wyznaczyc wyznacznika macierzy wiekszej niz 4x4 :(" << std::endl;
			return -1;
		}
	}
	else {
		std::cout << "Nie mozna wyznaczyc wyznacznika macierzy niekwadratowej" << std::endl;
		return -1;
	}

	
}

void Matrix::setMatrixAsTranspose(Matrix & m) {
	Matrix result(m.cols, m.rows);
	result.Multiply(0);
		for (int i = 0; i < m.rows; i++) {
			for (int j = 0; j < m.cols; j++) {
				result.matrix[i][j] = m.matrix[j][i];
			}
		}
		this->matrix = result.matrix;
	}

Matrix Matrix::getTransposeOfMatrix(Matrix m)  {
	Matrix result;
	result.setMatrixAsTranspose(m);
	return result;
}



Matrix Matrix::getInverseOfMatrix(Matrix m)
{
	// the returns shouldn't be there like this but i dont have energy to fix it
	if (m.rows != m.cols) {
		std::cout << "<=(Macierz nie jest kwadratowa, nei da sie :<)" << std::endl;
	}
	if (m.Determinant() == 0) {
		std::cout<<"(Wyznacznik macierzy jest rowny 0, ni da sie wyznaczyc macierzy odwrotnej)"<<std::endl;;
	}
	else 
	{
		Matrix result;
		float invDet = 1.0 / m.Determinant();

		if (m.cols == 2)
		{
			result = Matrix(2, 2);
			std::cout << "wyznacznik macierzy 2x2" << invDet << "\n";
			float d00 = m.matrix[1][1] * invDet;
			float d01 = m.matrix[1][0] * -1 * invDet;
			float d10 = m.matrix[0][1] * -1 * invDet;
			float d11 = m.matrix[0][0] * invDet;

			result.matrix[0][0] = d00;
			result.matrix[0][1] = d01;
			result.matrix[1][0] = d10;
			result.matrix[1][1] = d11;

			return result;

		}
		else if (m.cols == 3) {
			std::cout << "wyznacznik macierzy 3x3 "<< invDet<<"\n";
			result = Matrix(3, 3);
			float m0 = (m.matrix[1][1] * m.matrix[2][2] - m.matrix[1][2] * m.matrix[2][1]) * invDet;
			float m1 = (m.matrix[0][2] * m.matrix[2][1] - m.matrix[0][1] * m.matrix[2][2]) * invDet;
			float m2 = (m.matrix[0][1] * m.matrix[1][2] - m.matrix[0][2] * m.matrix[1][1]) * invDet;

			float m3 = (m.matrix[1][2] * m.matrix[2][0] - m.matrix[1][0] * m.matrix[2][2]) * invDet;
			float m4 = (m.matrix[0][0] * m.matrix[2][2] - m.matrix[0][2] * m.matrix[2][0]) * invDet;
			float m5 = (m.matrix[0][2] * m.matrix[1][0] - m.matrix[0][0] * m.matrix[1][2]) * invDet;

			float m6 = (m.matrix[1][0] * m.matrix[2][1] - m.matrix[1][1] * m.matrix[2][0]) * invDet;
			float m7 = (m.matrix[0][1] * m.matrix[2][0] - m.matrix[0][0] * m.matrix[2][1]) * invDet;
			float m8 = (m.matrix[0][0] * m.matrix[1][1] - m.matrix[0][1] * m.matrix[1][0]) * invDet;

			result.matrix[0][0] = m0;
			result.matrix[0][1] = m1;
			result.matrix[0][2] = m2;
			result.matrix[1][0] = m3;
			result.matrix[1][1] = m4;
			result.matrix[1][2] = m5;
			result.matrix[2][0] = m6;
			result.matrix[2][1] = m7;
			result.matrix[2][2] = m8;

			return result;

		}
		
		else if (m.cols == 4) {
			std::cout << "wyznacznik macierzy 4x4" << invDet << "\n";
			result = Matrix(4, 4);

			for (unsigned int i = 0; i < m.rows; i++) {
				for (unsigned int j = 0; j < m.cols; j++) {
					float cofactor = m.cofactorAt(i, j);
					result.matrix[i][j] = cofactor;
				}
			}
			result.setMatrixAsTranspose(result);
			result.Multiply(invDet);

			return result;


			/*
			result.matrix[0][0]
				= m.matrix[1][1] * m.matrix[2][2] * m.matrix[3][3]
				+ m.matrix[1][2] * m.matrix[2][3] * m.matrix[3][1]
				+ m.matrix[1][3] * m.matrix[2][1] * m.matrix[3][2]
				- m.matrix[1][1] * m.matrix[2][3] * m.matrix[3][2]
				- m.matrix[1][2] * m.matrix[2][1] * m.matrix[3][3]
				- m.matrix[1][3] * m.matrix[2][2] * m.matrix[3][1];
			result.matrix[0][1]
				= m.matrix[0][1] * m.matrix[2][3] * m.matrix[3][2] 
				+ m.matrix[0][2] * m.matrix[2][1] * m.matrix[3][3]
				+ m.matrix[0][3] * m.matrix[2][2] * m.matrix[3][1]
				- m.matrix[0][1] * m.matrix[2][2] * m.matrix[3][3]
				- m.matrix[0][2] * m.matrix[2][3] * m.matrix[3][1]
				- m.matrix[0][3] * m.matrix[2][1] * m.matrix[3][2];
			result.matrix[0][2]
				= m.matrix[0][1] * m.matrix[1][2] * m.matrix[3][3]
				+ m.matrix[0][2] * m.matrix[1][3] * m.matrix[3][1]
				+ m.matrix[0][3] * m.matrix[1][1] * m.matrix[3][2]
				- m.matrix[0][1] * m.matrix[1][3] * m.matrix[3][2]
				- m.matrix[0][2] * m.matrix[1][1] * m.matrix[3][3]
				- m.matrix[0][3] * m.matrix[1][2] * m.matrix[3][1];
			result.matrix[0][3]
				= m.matrix[0][1] * m.matrix[1][3] * m.matrix[3][2]
				+ m.matrix[0][2] * m.matrix[1][1] * m.matrix[3][3]
				+ m.matrix[0][3] * m.matrix[1][2] * m.matrix[3][1]
				- m.matrix[0][1] * m.matrix[1][2] * m.matrix[3][3]
				- m.matrix[0][2] * m.matrix[1][3] * m.matrix[3][1]
				- m.matrix[0][3] * m.matrix[1][1] * m.matrix[3][2];
			result.matrix[1][0]
				= m.matrix[1][0] * m.matrix[2][3] * m.matrix[3][2]
				+ m.matrix[1][2] * m.matrix[2][0] * m.matrix[3][3]
				+ m.matrix[1][3] * m.matrix[2][2] * m.matrix[3][0]
				- m.matrix[1][0] * m.matrix[2][2] * m.matrix[3][3]
				- m.matrix[1][2] * m.matrix[2][3] * m.matrix[3][0]
				- m.matrix[1][3] * m.matrix[2][0] * m.matrix[3][2];
			result.matrix[1][1]
				= m.matrix[0][1] * m.matrix[2][3] * m.matrix[3][2]
				+ m.matrix[0][2] * m.matrix[2][1] * m.matrix[3][3]
				+ m.matrix[0][3] * m.matrix[2][2] * m.matrix[3][1]
				- m.matrix[0][1] * m.matrix[2][2] * m.matrix[3][3]
				- m.matrix[0][2] * m.matrix[2][3] * m.matrix[3][1]
				- m.matrix[0][3] * m.matrix[2][1] * m.matrix[3][2];
				*/
		}
		else {
			std::cout << "Nie potrafimy wyznaczyc macierzy odwrotnej dla macierzy wiekszej niz 4x4 :(" << std::endl;

		}
	}
}

float Matrix::cofactorAt(unsigned int row, unsigned int col) const
{
	Matrix minor(rows - 1, cols - 1);
	for (unsigned int i = 0, r = 0; i < rows; i++) {
		if (i == row)
			continue;
		for (unsigned int j = 0, c = 0; j < cols; j++) {
			if (j == col)
				continue;
			minor.matrix[r][c] = matrix[i][j];
			c++;
		}
		r++;
	}

	return minor.Determinant() * ((row + col) % 2 == 0 ? 1.0 : -1.0);
}



void Matrix::Print() {
	for (int i = 0; i < rows; i++) {
		std::cout << "| ";
		for (int j = 0; j < cols; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "|" << std::endl;
	}
}








