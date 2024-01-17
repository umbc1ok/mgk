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
    int pointsInPlane[6][4] = { 0, 1, 2, 3, 1, 6, 5, 2, 6, 7, 4, 5, 7, 0, 3, 4, 3, 2, 5, 4, 0, 1, 6, 7 };

    Cube(float distance) {
        points[0] = Vector(-distance, -distance, -distance); //-+-
        points[1] = Vector(distance, -distance, -distance); //++-
        points[2] = Vector(distance, -distance, distance); //+++
        points[3] = Vector(-distance, -distance, distance); //-++
        points[4] = Vector(-distance, distance, distance); //--+
        points[5] = Vector(distance, distance, distance); //+-+
        points[6] = Vector(distance, distance, -distance); //+--
        points[7] = Vector(-distance, distance, -distance);  //---

        planes[0] = Plane(points[0], points[1], points[2], points[3]);
        planes[1] = Plane(points[1], points[6], points[5], points[2]);
        planes[2] = Plane(points[6], points[7], points[4], points[5]);
        planes[3] = Plane(points[7], points[0], points[3], points[4]);
        planes[4] = Plane(points[3], points[2], points[5], points[4]);
        planes[5] = Plane(points[0], points[1], points[6], points[7]);
    }

    bool checkIntersection(Line line) {
        Vector intersection = line.IntersectionWithPlane(planes[0]);
        //std::cout << line << std::endl;
        if (intersection.x >= points[0].x && intersection.x <= points[1].x &&
            intersection.z >= points[0].z && intersection.z <= points[3].z) {
            //std::cout << "0" << std::endl;
            return true;
        }

        intersection = line.IntersectionWithPlane(planes[1]);
        //std::cout << line << std::endl;
        if (intersection.y <= points[6].y && intersection.y >= points[1].y &&
            intersection.z >= points[1].z && intersection.z <= points[2].z) {
            //std::cout << "1" << std::endl;
            return true;
        }

        intersection = line.IntersectionWithPlane(planes[2]);
        //std::cout << line << std::endl;
        if (intersection.x >= points[7].x && intersection.x <= points[6].x &&
            intersection.z >= points[6].z && intersection.z <= points[5].z) {
            //std::cout << "2" << std::endl;
            return true;
        }

        intersection = line.IntersectionWithPlane(planes[3]);
        //std::cout << line << std::endl;
        if (intersection.y <= points[7].y && intersection.y >= points[0].y &&
            intersection.z >= points[0].z && intersection.z <= points[3].z) {
            //std::cout << "3" << std::endl;
            return true;
        }

        intersection = line.IntersectionWithPlane(planes[4]);
        //std::cout << line << std::endl;
        if (intersection.x >= points[3].x && intersection.x <= points[2].x &&
            intersection.y <= points[4].y && intersection.y >= points[3].y) {
            //std::cout << "4" << std::endl;
            return true;
        }

        intersection = line.IntersectionWithPlane(planes[5]);
        //std::cout << line << std::endl;
        if (intersection.x >= points[0].x && intersection.x <= points[1].x &&
            intersection.y <= points[7].y && intersection.y >= points[0].y) {
            //std::cout << "5" << std::endl;
            return true;
        }

        //std::cout << "NOT" << std::endl;
        return false;
    }
};

