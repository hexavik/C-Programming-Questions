/**
 * @file move_2d_point.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
} Point;

Point * create(int x, int y) {
    Point * new_point = (Point * )malloc(sizeof(Point));
    *((int * )new_point) = x;
    *((int * )new_point + 1) = y;
    return new_point;
}

void move(Point * p, int x, int y) {
    *((int * )p) = x;
    *((int * )p + 1) = y;
}

int main() {
    Point * p1 = create(5, 7);
    printf("p1 address: %p\n", p1);
    printf("x address: %p, val: %d\n", ((int * )p1), *((int * )p1));
    printf("y address: %p, val: %d\n", ((int * )p1 + 1), *((int * )p1 + 1));

    printf("\nPoint: (%d, %d)\n", *((int * )p1), *((int * )p1 + 1));
    move(p1, 10, 23);
    printf("Move: (%d, %d)\n", *((int * )p1), *((int * )p1 + 1));

    return 0;
}
