/**
 * @file 3d_point_distance.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-07-31
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <math.h>
#include <stdio.h>

typedef struct Point {
    float x;
    float y;
    float z;
} Point;

//
// Avoid #define (macro) for the type safety and miscalculation
//
double square(float num) {
    return num * num;
}

//
// The distance formula for two 3D points
// D = Sqrt((x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2)
//
double distance_calculate(Point* p1, Point* p2) {
    if (!p1 || !p2) { return 0.0f; }

    return
    sqrt(square(p2->x - p1->x) +
         square(p2->y - p1->y) +
         square(p2->z - p1->z));
}

int main() {
    Point p1 = { .x = 1.0, .y = 2.0, .z = 3.0 };
    Point p2 = { .x = 4.0, .y = 6.0, .z = 8.0 };

    printf("Distance: %f\n", distance_calculate(&p1, &p2));

    return 0;
}
