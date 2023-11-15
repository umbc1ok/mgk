#pragma once
class Matrix
{
	public:
		int rows;
		int cols;
		int** matrix;

		Matrix(int rows, int cols) {

		};
		Matrix();
		~Matrix();
		int getRows();
		int getCols();

};

