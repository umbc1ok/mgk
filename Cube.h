#pragma once

#include "Matrix.h"
#include "Plane.h"
#include "Line.h"
#include "CommonMatricies.h"

#include <vector>
#include <iostream>

class Cube
{
public:
	Matrix transformMatrix;
	Vector center;
		float width;
		float height;
		float depth;
		std::vector<Plane> planes;
		//std::vector<Line> edges;



		Cube(Vector center, float width, float height, float depth) 
			: center(center), width(width), height(height), depth(depth), transformMatrix(4,4) {
			transformMatrix = Matrix();
			Vector front = center + Vector(center.x, center.y, center.z + depth / 2);
			Vector back = center + Vector(center.x, center.y, center.z - depth / 2);
			Vector left = center + Vector(center.x - width / 2, center.y, center.z);
			Vector right = center + Vector(center.x + width / 2, center.y, center.z);
			Vector top = center + Vector(center.x, center.y + height / 2, center.z);
			Vector bottom = center + Vector(center.x, center.y - height / 2, center.z);

			planes.push_back(Plane(front, Vector(0, 0, 1)));
			planes.push_back(Plane(back, Vector(0, 0, -1)));
			planes.push_back(Plane(left, Vector(-1, 0, 0)));
			planes.push_back(Plane(right, Vector(1, 0, 0)));
			planes.push_back(Plane(top, Vector(0, 1, 0)));
			planes.push_back(Plane(bottom, Vector(0, -1, 0)));

		}

		bool intersects(Line line) const {
			const float halfWidth = width / 2.0f;
			const float halfHeight = height / 2.0f;
			const float halfDepth = depth / 2.0f;

			// Transform the line into the cube's local coordinate system
			const Matrix inverseTransform = Matrix::getInverseOfMatrix(transformMatrix);
			Line localLine = Line(inverseTransform * line.p, inverseTransform.getRotationPart() * line.v.normalize());

			constexpr float epsilon = 0.00005f;

			for (auto const& plane : planes)
			{
				const Vector normal = plane.normal;
				const Vector Q = plane.p;
				const Vector P = localLine.p;
				const Vector V = localLine.v;

				const float t = ((Q - P).dot(normal)) / (V.dot(normal));

				if (t >= 0.0f)
				{
					const Vector intersection = P + (V * t);

					if (std::abs(intersection.x - center.x) <= halfWidth + epsilon &&
						std::abs(intersection.y - center.y) <= halfHeight + epsilon &&
						std::abs(intersection.z - center.z) <= halfDepth + epsilon)
					{
						return true;
					}
				}
			}

			return false;
		}

			
		

		void rotate(float angle, Vector axis) {
			Matrix rotationMatrix = Matrix(3, 3);

			if (axis == Vector(1,0,0))
			{
				rotationMatrix = RotationX(angle);
			}
			else if (axis == Vector(0, 1, 0))
			{
				rotationMatrix = RotationY(angle);
			}
			else if (axis == Vector(0, 0, 1))
			{
				rotationMatrix = RotationZ(angle);
			}
			else
			{
				std::cout << "Wrong axis!" << std::endl;
				return;
			}

			Matrix extendedRotationMatrix;
			extendedRotationMatrix.extendMatrix(rotationMatrix);
			transformMatrix = transformMatrix.Multiply(extendedRotationMatrix);

			//TRZEBA DODAC MNOZENIE MATRIX * VECTOR!!!

			for (auto& plane : planes)
			{
				plane.p = extendedRotationMatrix * ((plane.p - center) + center);
				Matrix temp = Matrix::getTransposeOfMatrix(Matrix::getInverseOfMatrix(extendedRotationMatrix));
				plane.normal = (temp * plane.normal).normalize();
			}

		}




};

