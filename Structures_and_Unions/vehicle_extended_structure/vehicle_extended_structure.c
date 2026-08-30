/**
 * @file vehicle_extended_structure.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-08-30
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

typedef struct Vehicle {
    float weight;
    float max_speed;
} Vehicle;

typedef struct Car {
    Vehicle base;
    int seating_capacity;
} Car;

typedef struct Truck {
    Vehicle base;
    float max_load;
} Truck;

int main() {
    Truck my_truck = {{ 8000.0f, 120.0f }, 5000.0f };

    printf("Truck Weight: %.1f kg\n", my_truck.base.weight);
    printf("Truck Speed: %.1f km/h\n", my_truck.base.max_speed);
    printf("Can load up to %.1f kg\n", my_truck.max_load);

    return 0;
}
