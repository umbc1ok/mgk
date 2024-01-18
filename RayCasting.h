#pragma once
#include "Vector.h"
#include "Line.h"
#include "Quaternion.h"
#include <vector>
#include <iostream>
#include "Plane.h"
#include "Cube.h"
#include "Intersections.h"
#include <windows.h>
#include <sstream>

#include "Cube.h"

constexpr int NUM_PIXELS = 60;
class RayCasting
{
	const float POINTS_CAM_DIST = 5;
	const float POINTS_WIDTH = 10;
	const Vector START_POS = Vector(0, -15, 0);

public:
	Vector position;
	RayCasting()
	{
		this->position = START_POS;

		for (int i = 0; i < 60; i++) {
			for (int j = 0; j < 60; j++) {
				viewPoints[i][j].x = (j - 30) * POINTS_WIDTH / 60;
				viewPoints[i][j].y = START_POS.y + POINTS_CAM_DIST;
				viewPoints[i][j].z = (i - 30) * POINTS_WIDTH / 60;
			}
		}
	}
	Vector rotatePoint(Vector point, float Xrot, float yRot, float zRot) {

		Quaternion p(point.x, point.y, point.z, 0);
		Vector ok;
		if (Xrot != 0) {
			Vector test(1, 0, 0);
			 ok = p.rotate(point, test,Xrot);
		}
		if (yRot != 0) {
			Vector test(0, 1, 0);
			ok = p.rotate(ok, test, yRot);
		}
		if (zRot != 0) {
			Vector test(0, 0, 1);
			ok = p.rotate(ok, test, zRot);
		}



		return ok;
	}
	void rotate(float roll, float pitch, float yaw) {

			position = rotatePoint(position, roll, pitch, yaw);

			for (int i = 0; i < 60; i++) {
				for (int j = 0; j < 60; j++) {
					viewPoints[i][j] = rotatePoint(viewPoints[i][j], roll, pitch, yaw);
				}
			}
	}

	void zoom(float distance) {
		Vector v(0, 0, 0);
		v = v - position; 
		float length = v.length();
		v.div(length);
		v.mul(distance);
		for (int i = 0; i < 60; i++) {
			for (int j = 0; j < 60; j++) {
				viewPoints[i][j] = viewPoints[i][j] + v; 
			}
		}
	}


	Vector viewPoints[60][60];
	std::string rayCasting(Cube cube, std::string currentConsoleState) {
		std::string result = "";
		for (int i = 0; i < 60; i++) {
			for (int j = 0; j < 60; j++) {
				Vector v = viewPoints[i][j];
				v = v - position; 
				Line line(viewPoints[i][j], v);
				if (cube.checkIntersection(line))
				{
					result+="0";
					if (currentConsoleState[i * 60 + j] != '0') {
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(i), SHORT(j) });
						std::cout << '0';
					}
				}
				else {
					result += ".";
					if (currentConsoleState[i * 60 + j] != '.') {
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(i), SHORT(j) });
						std::cout << '.';
					}
				}
			}
			
		}
		return result;
	}
	void reset() {
		this->position = START_POS;

		for (int i = 0; i < 60; i++) {
			for (int j = 0; j < 60; j++) {
				viewPoints[i][j].x = (j - 30) * POINTS_WIDTH / 60;
				viewPoints[i][j].y = START_POS.y + POINTS_CAM_DIST;
				viewPoints[i][j].z = (i - 30) * POINTS_WIDTH / 60;
			}
		}
	}
	void changeTransform(float yRot, float xRot, float zRot, float z) {
		reset();
		rotate(yRot, xRot, zRot);
		zoom(z);
	}
	
};
