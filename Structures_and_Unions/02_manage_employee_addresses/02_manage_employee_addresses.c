/**
 * @file employee_address.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-07-31
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdio.h>

//
// Nested Structure
//
typedef struct Employee {
    char* name;

    // Embedded inner structure
    struct Address {
        char* street;
        char* city;
        char* state;
        char* zip;
    } addr; // Variable declaration is mandatory here
} Employee;

void employee_address_display(Employee* employee) {
    if (!employee) { printf("Bad Input\n"); return; }

    printf("Address: %s, %s, %s, %s\n",
        employee->addr.street,
        employee->addr.city,
        employee->addr.state,
        employee->addr.zip);
}

int main() {
    Employee emp1 = {
        .name = "Bob",
        .addr = {
            .street = "456 Maple Rd",
            .city = "Brookfield",
            .state = "WI",
            .zip = "53005"
        }
    };

    employee_address_display(&emp1);

    return 0;
}
