#include "Matrix4x4.h"
#include <iostream>
#include <iomanip>
#include "Vector.h"
#include <math.h>
#include <corecrt_math_defines.h>

#define _USE_MATH_DEFINES


Matrix4x4::Matrix4x4(float data[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = data[i][j];
        }
    }
}

void Matrix4x4::print() const {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << std::setw(8) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix4x4::LoadIdentity()
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = 0;
            if (i == j)
                matrix[i][j] = 1;
        }
    }

}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& other) const {
    Matrix4x4 result;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& other) const {
    Matrix4x4 result;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return result;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& other) const {
    Matrix4x4 result;
    float sum = 0;
    for (int i = 0; i < 4; ++i) {
        for (int k = 0; k < 4; ++k) {
            sum = 0;
            for (int j = 0; j < 4; ++j) {
                sum += matrix[i][j] * other.matrix[j][k];
            }
            result.matrix[i][k] = sum;
        }
    }
    return result;
}

Matrix4x4 Matrix4x4::operator*(const float& other) const {
    Matrix4x4 result;
    float sum = 0;
    for (int i = 0; i < 4; ++i) {
        for (int k = 0; k < 4; ++k) {
            result.matrix[i][k] = matrix[i][k] * other;
        }
    }
    return result;
}

void Matrix4x4::setMatrixAsInsversionOfGivenMatrix(const Matrix4x4& other)
{
    float t1 = other.matrix[0][0] * other.matrix[1][0];
    float t2 = other.matrix[0][0] * other.matrix[1][3];
    float t3 = other.matrix[0][3] * other.matrix[0][1];
    float t4 = other.matrix[1][2] * other.matrix[0][1];
    float t5 = other.matrix[0][3] * other.matrix[0][2];
    float t6 = other.matrix[1][2] * other.matrix[0][2];

    //calculate the determinant
    float det = t1 * other.matrix[2][0] - t2 * other.matrix[1][1] - t3 * other.matrix[2][0] + t4 * other.matrix[1][3] + t5 * other.matrix[2][1] - t6 * other.matrix[1][0];

    if (det == 0)
        return;

    float invdet = 1 / det;

    float m0 = (other.matrix[1][0] * other.matrix[2][0] - other.matrix[1][3] * other.matrix[1][1]) * invdet;
    float m3 = (other.matrix[0][3] * other.matrix[2][0] - other.matrix[1][2] * other.matrix[1][1]) * invdet;
    float m6 = (other.matrix[0][3] * other.matrix[1][3] - other.matrix[1][2] * other.matrix[1][0]) * invdet;
    float m1 = (other.matrix[0][1] * other.matrix[2][0] - other.matrix[1][3] * other.matrix[0][2]) * invdet;
    float m4 = (other.matrix[0][0] * other.matrix[2][0] - t6) * invdet;
    float m7 = (t2 - t4) * invdet;
    float m2 = (other.matrix[0][1] * other.matrix[1][1] - other.matrix[1][0] * other.matrix[0][2]) * invdet;
    float m5 = (other.matrix[0][0] * other.matrix[1][1] - t5) * invdet;
    float m8 = (t1 - t3) * invdet;

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

Matrix4x4 Matrix4x4::getInversionOfMatrix() const
{
    Matrix4x4 result;
    result.setMatrixAsInsversionOfGivenMatrix(*this);
    return result;
}

void Matrix4x4::invertMatrix()
{
    setMatrixAsInsversionOfGivenMatrix(*this);
}



// These 3 are exclusively for 4x4 matrices
void Matrix4x4::SetRotationX(const double angle) {
    LoadIdentity();
    matrix[1][1] = (float)cos(M_PI * angle / 180);
    matrix[2][1] = (float)sin(M_PI * angle / 180);

    matrix[1][2] = -matrix[2][1];
    matrix[2][2] = matrix[1][1];
}

void Matrix4x4::SetRotationY(const double angle) {
    LoadIdentity();
    matrix[0][0] = (float)cos(M_PI * angle / 180);
    matrix[0][2] = (float)sin(M_PI * angle / 180);

    matrix[2][2] = matrix[0][0];
    matrix[2][0] = -matrix[0][2];
}

void Matrix4x4::SetRotationZ(const double angle) {
    LoadIdentity();
    matrix[0][0] = (float)cos(M_PI * angle / 180);
    matrix[0][1] = -(float)sin(M_PI * angle / 180);

    matrix[1][0] = -matrix[0][1];
    matrix[1][1] = matrix[0][0];
}
