#define _USE_MATH_DEFINES
#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "CommonMatricies.h"
#include "Quaternion.h"
#include "Line.h"
#include "Intersections.h"
#include "RayCasting.h"




int main() {
	Cube cube(5);
	RayCasting camera;

	float fifteen = M_PI / 12;

	float roll = 0, pitch = 0, yaw = 0, zoom = 0;
	float rollR = 0, pitchR = 0, yawR = 0;

	for (;;)
	{
		system("CLS");
		std::cout << camera.rayCasting(cube);
		std::cout << std::endl << "rotX: " << roll << " rotY: " << pitch << " rotZ: " << yaw << std::endl;

		std::cout << std::endl << std::endl;

		std::cout << " |Z" << std::endl;
		std::cout << " |   /Y" << std::endl;
		std::cout << " |  / " << std::endl;
		std::cout << " | / " << std::endl;
		std::cout << " |/______ X   " << std::endl << std::endl;


		if (GetKeyState('W') & 0x8000) {
			zoom += 0.1;
		}
		if (GetKeyState('S') & 0x8000) {
			zoom -= 0.1;
		}
		if (GetKeyState('A') & 0x8000) {
			roll -= 0.1;
		}
		if (GetKeyState('D') & 0x8000) {
			roll += 0.1;
		}
		if (GetKeyState('Q') & 0x8000) {
			pitch -= 0.1;
		}
		if (GetKeyState('E') & 0x8000) {
			pitch += 0.1;
		}
		if (GetKeyState('Z') & 0x8000) {
			yaw -= 0.1;
		}
		if (GetKeyState('C') & 0x8000) {
			yaw += 0.1;
		}



		rollR = M_PI * roll / 180;
		pitchR = M_PI * pitch / 180;
		yawR = M_PI * -yaw / 180;
		camera.changeTransform(rollR, pitchR, yawR, zoom);
	}
}

