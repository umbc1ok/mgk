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
	clearBuffer();

	Cube cube(Vector(0.0f, 0.0f, 0.0f), 1.0f, 1.0f, 1.0f);
	Renderer::cubes.emplace_back(cube);

	float flow = -10000.0f;
	float rotation = 1.0f;
	bool once = true;

    while (true)
    {
        flow += 0.01f;
        //rotation += 0.0001f;
        for (auto& sphere : Renderer::spheres)
        {
            sphere.radius = sin(flow);
        }

        //if (once)
        {
            for (auto& cube : Renderer::cubes)
            {
                cube.rotate(rotation, Vector(0.0f, 1.0f, 0.0f));
                //cube.rotate(rotation, Vector(1.0f, 0.0f, 0.0f));
                //cube.rotate(rotation, Vector(0.0f, 0.0f, 1.0f));
                //cube.center = Vector(sin(flow), sin(flow), 0.0f);
                once = false;
            }
        }

        render();
    }
}

