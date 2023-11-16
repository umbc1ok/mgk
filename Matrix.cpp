#pragma once

#include <iomanip>
#include "Matrix.h"
#include <iostream>

/*
v dodawanie
v odejmowanie
v mno�enie przez skalar
v mno�enie przez macierz
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
		for (int i = 0; i < m.rows; i++) {
			for (int j = 0; j < m.cols; j++) {
				result.matrix[i][j] = m.matrix[j][i];
			}
		}
		this->matrix = result.matrix;
	}

Matrix Matrix::getTransposeOfMatrix()  {
	Matrix result;
	result.setMatrixAsTranspose(*this);
	return result;
}

Matrix Matrix::getInverseOfMatrix(Matrix& m) const
{
	// the returns shouldn't be there like this but i dont have energy to fix it
	if (m.rows != m.cols) {
		std::cout << "<=(Macierz nie jest kwadratowa, nei da sie :<)" << std::endl;
		return Matrix();
	}
	if (m.Determinant() == 0) {
		std::cout<<"(Wyznacznik macierzy jest rowny 0, ni da sie wyznaczyc macierzy odwrotnej)"<<std::endl;
		return Matrix();
	}
	else 
	{
		Matrix result;
		float invDet = 1.0 / m.Determinant();

		float t1 = m.matrix[0][0] * m.matrix[1][0];
		float t2 = m.matrix[0][0] * m.matrix[1][3];
		float t3 = m.matrix[0][3] * m.matrix[0][1];
		float t4 = m.matrix[1][2] * m.matrix[0][1];
		float t5 = m.matrix[0][3] * m.matrix[0][2];
		float t6 = m.matrix[1][2] * m.matrix[0][2];

		if (m.cols == 2)
		{

		}
		if (m.cols == 3) {

		}
		
		if (m.cols == 4) {

			float m0 = (m.matrix[1][0] * m.matrix[2][0] - m.matrix[1][3] * m.matrix[1][1]) * invDet;
			float m3 = (m.matrix[0][3] * m.matrix[2][0] - m.matrix[1][2] * m.matrix[1][1]) * invDet;
			float m6 = (m.matrix[0][3] * m.matrix[1][3] - m.matrix[1][2] * m.matrix[1][0]) * invDet;
			float m1 = (m.matrix[0][1] * m.matrix[2][0] - m.matrix[1][3] * m.matrix[0][2]) * invDet;
			float m4 = (m.matrix[0][0] * m.matrix[2][0] - t6) * invDet;
			float m7 = (t2 - t4) * invDet;
			float m2 = (m.matrix[0][1] * m.matrix[1][1] - m.matrix[1][0] * m.matrix[0][2]) * invDet;
			float m5 = (m.matrix[0][0] * m.matrix[1][1] - t5) * invDet;
			float m8 = (t1 - t3) * invDet;



			matrix[0][0] = m0;
			matrix[0][3] = m3;
			matrix[1][2] = m6;

			matrix[0][1] = m1;
			matrix[1][0] = m4;
			matrix[1][3] = m7;

			matrix[0][2] = m2;
			matrix[1][1] = m5;
			matrix[2][0] = m8;
		}
	}
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








