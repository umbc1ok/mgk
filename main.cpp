#define _USE_MATH_DEFINES
#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "CommonMatricies.h"
#include "Quaternion.h"
#include "Line.h"
#include "Intersections.h"



int main() {


	// ZAD1 + ZAD2
	{
		Line l1({ -2, 5, 0 }, { 3, 1, 5 });
		Line l2({ -2, 4, 0 }, { 1, -5, 3 });

		Vector v = intersection(l1, l2);
		std::cout << v.ToString() << std::endl;

		std::cout << angleBetween(l1, l2) * 180.0f / M_PI << std::endl;
	}

	//ZAD3 + ZAD4
	{
		Line l1({ -2, 2, -1 }, { 3, -1, 2 });
		Plane p(2, 3, 3, -8);

		Vector v = intersection(l1, p);

		std::cout << v.ToString() << std::endl;

		std::cout << angleBetween(l1, p) << std::endl;
	}


	// ZAD 5 + 6
	{
		Plane p1(2, -1, 1, -8);
		Plane p2(4, 3, 1, 14);

		Line result = intersection(p1, p2);

		std::cout << "P: " << result.p.ToString() << ", V: " << result.v.ToString() << std::endl;

		std::cout << angleBetween(p1, p2) * 180 / M_PI << std::endl;
	}

	// ZAD 7
	{
		LineSegment l1({ 5,5,4 }, { 10,10,6 });
		LineSegment l2({ 5,5,5 }, { 10, 10, 3 });

		auto result = intersection(l1, l2);

		if (result.ToString() == Vector(NAN,NAN,NAN).ToString())
			std::cout << "No intersections between the two line segments." << std::endl;
		else
			std::cout << result.ToString() << std::endl;
	}


	//ZAD OSTATNIE
	{
		Sphere s({ 0.0f, 0.0f, 0.0f }, sqrt(26.0f));
		Line l({ 3, -1, 2 }, { 2, 4, -6 });

		auto result = intersection(s, l);

		if (result.first.ToString() == Vector(NAN, NAN, NAN).ToString())
			std::cout << "No intersections between the sphere and the line." << std::endl;
		else
			std::cout << "Sphere and line, Intersections at: " << result.first.ToString() << ", " << result.second.ToString() << std::endl;
	}


}

