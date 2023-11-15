#include "Matrix.h"
#include <iostream>

/*
v dodawanie
v odejmowanie
v mno¿enie przez skalar
v mno¿enie przez macierz
v macierz jednostkowa
- transponowanie
- macierz odwrotna
v > wyznacznik do 4x4
*/


Matrix::Matrix(int rows, int cols)
{
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
void Matrix::Multiply(Matrix& other) {
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
		this->rows = result.rows;
		this->cols = result.cols;
		this->matrix = result.matrix;
	}
	else {
		std::cout << "Nie mozna pomnozyc macierzy o roznych wymiarach" << std::endl;
	}
}
float Matrix::Determinant()
{
	if (this->cols == this->rows) {
		if (cols == 1) {
			return matrix[0][0];
		}
		else if (cols == 2) {
			return matrix[0][0]* matrix[1][1] - matrix[0][1] * matrix[1][0];
		}
		else if (cols == 3) {
			return matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[0][1] * matrix[1][0] * matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1];
		}
		else if (cols == 4) {

			// not sure if it's the right way but I dont care
			float t1 = matrix[0][0] * matrix[1][0];
			float t2 = matrix[0][0] * matrix[1][3];
			float t3 = matrix[0][3] * matrix[0][1];
			float t4 = matrix[1][2] * matrix[0][1];
			float t5 = matrix[0][3] * matrix[0][2];
			float t6 = matrix[1][2] * matrix[0][2];

			//calculate the determinant
			float det = t1 * matrix[2][0] - t2 * matrix[1][1] - t3 * matrix[2][0] + t4 * matrix[1][3] + t5 * matrix[2][1] - t6 * matrix[1][0];
			return det;
		}
		else {
			std::cout << "Nie potrafimy wyznaczyc wyznacznika macierzy wiekszej niz 4x4 :(" << std::endl;
		}
	}
	else {
		std::cout << "Nie mozna wyznaczyc wyznacznika macierzy niekwadratowej" << std::endl;
	}
}











