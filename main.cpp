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
	float roll = 0, pitch = 0, yaw = 0, zoom = 0;
	float rollR = 0, pitchR = 0, yawR = 0;

	for (;;)
	{
		system("CLS");
		printf(camera.rayCasting(cube).c_str());

		if (GetKeyState('W') & 0x8000) {
			zoom += ZOOM_SPEED;
		}
		if (GetKeyState('S') & 0x8000) {
			zoom -= ZOOM_SPEED;
		}
		if (GetKeyState('A') & 0x8000) {
			roll -= ROTATE_SPEED;
		}
		if (GetKeyState('D') & 0x8000) {
			roll += ROTATE_SPEED;
		}
		if (GetKeyState('Q') & 0x8000) {
			pitch -= ROTATE_SPEED;
		}
		if (GetKeyState('E') & 0x8000) {
			pitch += ROTATE_SPEED;
		}
		if (GetKeyState('Z') & 0x8000) {
			yaw -= ROTATE_SPEED;
		}
		if (GetKeyState('C') & 0x8000) {
			yaw += ROTATE_SPEED;
		}

		rollR = M_PI * roll / 180;
		pitchR = M_PI * pitch / 180;
		yawR = M_PI * yaw / 180;


		camera.changeTransform(rollR, pitchR, yawR, zoom);
	}
}

