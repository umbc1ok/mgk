#define _USE_MATH_DEFINES
#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "CommonMatricies.h"
#include "Quaternion.h"
#include "Line.h"
#include "Intersections.h"
#include "RayCasting.h"

#define ROTATE_SPEED 1
#define ZOOM_SPEED 0.1


int main() {
	Cube cube(5);
	RayCasting camera;

	float fifteen = M_PI / 12;
	float yRot = 0, xRot = 0, zRot = 0, zoom = 0;
	float yRotR = 0, xRotR = 0, zRotR = 0;
	std::string output(3600, ' ');
	for (;;)
	{
		//system("CLS");
		output = camera.rayCasting(cube,output);

		//roll += ROTATE_SPEED;
		//pitch += ROTATE_SPEED;
		//yaw += ROTATE_SPEED;

		if (GetKeyState('W') & 0x8000) {
			zoom += ZOOM_SPEED;
		}
		if (GetKeyState('S') & 0x8000) {
			zoom -= ZOOM_SPEED;
		}
		if (GetKeyState('Q') & 0x8000) {
			xRot -= ROTATE_SPEED;
		}
		if (GetKeyState('E') & 0x8000) {
			xRot += ROTATE_SPEED;
		}
		if (GetKeyState('A') & 0x8000) {
			yRot -= ROTATE_SPEED;
		}
		if (GetKeyState('D') & 0x8000) {
			yRot += ROTATE_SPEED;
		}
		if (GetKeyState('Z') & 0x8000) {
			zRot -= ROTATE_SPEED;
		}
		if (GetKeyState('C') & 0x8000) {
			zRot += ROTATE_SPEED;
		}

		//wartosci w radianach
		yRotR = M_PI * yRot / 180;
		xRotR = M_PI * xRot / 180;
		zRotR = M_PI * zRot / 180;


		camera.changeTransform(yRotR, xRotR, zRotR, zoom);
	}
}

