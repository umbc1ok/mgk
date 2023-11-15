#include "Matrix.h"
#include <corecrt_math_defines.h>
#include <corecrt_math.h>

#define _USE_MATH_DEFINES
// it's basing on a constructor that zeros the matrix
Matrix GetIdentity(int size)
{
	Matrix result = Matrix(size, size);
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (i == j) {
				result.matrix[i][j] = 1;
			}
		}
	}

}


Matrix RotationX(const double angle) {
	Matrix matrix = GetIdentity(4);
	matrix.matrix[1][1] = (float)cos(M_PI * angle / 180);
	matrix.matrix[2][1] = (float)sin(M_PI * angle / 180);

	matrix.matrix[1][2] = -matrix.matrix[2][1];
	matrix.matrix[2][2] = matrix.matrix[1][1];
}

Matrix RotationY(const double angle) {
	Matrix matrix = GetIdentity(4);
	matrix.matrix[0][0] = (float)cos(M_PI * angle / 180);
	matrix.matrix[0][2] = (float)sin(M_PI * angle / 180);

	matrix.matrix[2][2] = matrix.matrix[0][0];
	matrix.matrix[2][0] = -matrix.matrix[0][2];
}

Matrix RotationZ(const double angle) {
	Matrix matrix = GetIdentity(4);
	matrix.matrix[0][0] = (float)cos(M_PI * angle / 180);
	matrix.matrix[0][1] = -(float)sin(M_PI * angle / 180);

	matrix.matrix[1][0] = -matrix.matrix[0][1];
	matrix.matrix[1][1] = matrix.matrix[0][0];
}

