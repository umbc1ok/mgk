#pragma once

#include "Vector.h"

class Sphere
{
public:
    Sphere(const Vector& p, float radius){
		point = p;
		this->radius = radius;
	}

    Vector point;
    float radius;
};