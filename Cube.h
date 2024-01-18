#pragma once

#include "Matrix.h"
#include "Plane.h"
#include "Line.h"
#include "CommonMatricies.h"
#include "Intersections.h"

#include <vector>
#include <iostream>

class Cube
{
public:
    Vector points[8];
    Plane planes[6];

    Cube(float size) {
        points[0] = Vector(-size, -size, -size); //-+-
        points[1] = Vector(size, -size, -size); //++-
        points[2] = Vector(size, -size, size); //+++
        points[3] = Vector(-size, -size, size); //-++
        points[4] = Vector(-size, size, size); //--+
        points[5] = Vector(size, size, size); //+-+
        points[6] = Vector(size, size, -size); //+--
        points[7] = Vector(-size, size, -size);  //---

        planes[0] = Plane(points[0], points[1], points[2], points[3]);
        planes[1] = Plane(points[1], points[6], points[5], points[2]);
        planes[2] = Plane(points[6], points[7], points[4], points[5]);
        planes[3] = Plane(points[7], points[0], points[3], points[4]);
        planes[4] = Plane(points[3], points[2], points[5], points[4]);
        planes[5] = Plane(points[0], points[1], points[6], points[7]);
    }

    bool checkIntersection(Line line) {
        // Dla kazdego plane'a sprawdzamy czy linia go przecina
        // Jesli tak to sprawdzamy czy punkt przeciecia nalezy do boku szeszescianu
        // czyli czy x nalezy do przedzialu [x1, x2] i y nalezy do przedzialu [y1, y2] itd.

        Vector intersection = line.IntersectionWithPlane(planes[0]);
        if (intersection.x >= points[0].x && intersection.x <= points[1].x &&
            intersection.z >= points[0].z && intersection.z <= points[3].z) {
            return true;
        }

        intersection = line.IntersectionWithPlane(planes[1]);
        if (intersection.y <= points[6].y && intersection.y >= points[1].y &&
            intersection.z >= points[1].z && intersection.z <= points[2].z) {
            return true;
        }

        intersection = line.IntersectionWithPlane(planes[2]);
        if (intersection.x >= points[7].x && intersection.x <= points[6].x &&
            intersection.z >= points[6].z && intersection.z <= points[5].z) {
            return true;
        }

        intersection = line.IntersectionWithPlane(planes[3]);
        if (intersection.y <= points[7].y && intersection.y >= points[0].y &&
            intersection.z >= points[0].z && intersection.z <= points[3].z) {
            return true;
        }

        intersection = line.IntersectionWithPlane(planes[4]);
        if (intersection.x >= points[3].x && intersection.x <= points[2].x &&
            intersection.y <= points[4].y && intersection.y >= points[3].y) {
            return true;
        }

        intersection = line.IntersectionWithPlane(planes[5]);
        if (intersection.x >= points[0].x && intersection.x <= points[1].x &&
            intersection.y <= points[7].y && intersection.y >= points[0].y) {
            return true;
        }

        return false;
    }
};

