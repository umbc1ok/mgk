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
	Vector rotatePoint(Vector point, float roll, float pitch, float yaw) {
		Quaternion p(point.x, point.y, point.z, 0);
		float u = -roll;
		float v = -pitch;
		float w = yaw;
		Quaternion q;
		q.w = cos(u / 2) * cos(v / 2) * cos(w / 2) + sin(u / 2) * sin(v / 2) * sin(w / 2);
		q.x = sin(u / 2) * cos(v / 2) * cos(w / 2) - cos(u / 2) * sin(v / 2) * sin(w / 2);
		q.y = cos(u / 2) * sin(v / 2) * cos(w / 2) + sin(u / 2) * cos(v / 2) * sin(w / 2);
		q.z = cos(u / 2) * cos(v / 2) * sin(w / 2) - sin(u / 2) * sin(v / 2) * cos(w / 2);
		Quaternion qinverted = q.conjugate(); 
		Quaternion pnew = qinverted * p * q;
		Vector result;
		result.x = pnew.x;
		result.y = pnew.y;
		result.z = pnew.z;
		return result;
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
	std::string rayCasting(Cube cube) {
		std::string result = "";
		for (int i = 0; i < 60; i++) {
			for (int j = 0; j < 60; j++) {
				Vector v = viewPoints[i][j];
				v = v - position; 
				Line line(viewPoints[i][j], v);
				if (cube.checkIntersection(line))
				{
					result += '0';
				}
				else {
					result += '.';
				}
			}
			result += "\n";
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
	void changeTransform(float roll, float pitch, float yaw, float z) {
		reset();
		rotate(roll, pitch, yaw);
		zoom(z);
	}
	
};
