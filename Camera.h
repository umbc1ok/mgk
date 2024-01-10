#pragma once
#include "Vector.h"
#include "Line.h"
#include "Quaternion.h"
#include <vector>
#include <iostream>

class Camera
{
public:
    Vector position;
    Quaternion rotation;
    float zoomLevel;

    Camera() : zoomLevel(1.0f) {}

    void rotate(float angle, Vector axis) {
        Vector rotatedPosition = rotation.rotate(position, axis, angle);
    }

    void zoom(float factor) {
        zoomLevel *= factor;
    }
};

class RayCasting {
public:
    Camera camera;
    int gridSize;
    std::vector<std::vector<char>> grid;

    RayCasting(int size) : gridSize(size), grid(size, std::vector<char>(size, '.')) {}

    void createCube(Vector center, float size) {

        Vector vertices[8];
        vertices[0] = center + Vector(-size / 2, -size / 2, -size / 2);
        vertices[1] = center + Vector(size / 2, -size / 2, -size / 2);
        vertices[2] = center + Vector(size / 2, size / 2, -size / 2);
        vertices[3] = center + Vector(-size / 2, size / 2, -size / 2);
        vertices[4] = center + Vector(-size / 2, -size / 2, size / 2);
        vertices[5] = center + Vector(size / 2, -size / 2, size / 2);
        vertices[6] = center + Vector(size / 2, size / 2, size / 2);
        vertices[7] = center + Vector(-size / 2, size / 2, size / 2);

        // Przetrzymujemy œciany szeœcianu jako pary indeksów wierzcho³ków
        int cubeEdges[12][2] = {
            {0, 1}, {1, 2}, {2, 3}, {3, 0},
            {4, 5}, {5, 6}, {6, 7}, {7, 4},
            {0, 4}, {1, 5}, {2, 6}, {3, 7}
        };

        for (int i = 0; i < 8; ++i) {
            int x = static_cast<int>(vertices[i].x);
            int y = static_cast<int>(vertices[i].y);
            if (x >= 0 && x < gridSize && y >= 0 && y < gridSize) {
                grid[x][y] = 'O';
            }
        }
    }

    void drawLineSegmentOnGrid(LineSegment segment) {

    }

    void castRays() {

    }

    void displayResult() {
        for (const auto& row : grid) {
            for (char cell : row) {
                std::cout << cell << ' ';
            }
            std::cout << std::endl;
        }
    }
};