/**
 * @file complex_number_operations.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-08-01
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdint.h>
#include <stdio.h>

typedef struct ComplexNum {
    int real;
    int imaginary;
} ComplexNum;

ComplexNum complex_add(ComplexNum n1, ComplexNum n2) {
    ComplexNum result = {
        n1.real + n2.real,
        n1.imaginary + n2.imaginary
    };
    return result;
}

ComplexNum complex_subtract(ComplexNum n1, ComplexNum n2) {
    ComplexNum result = {
        n1.real - n2.real,
        n1.imaginary > n2.imaginary ?
        n1.imaginary - n2.imaginary :
        n2.imaginary - n1.imaginary
    };
    return result;
}

ComplexNum complex_multiply(ComplexNum n1, ComplexNum n2) {
    ComplexNum result;
    result.real = (n1.real * n2.real) - (n2.imaginary * n2.imaginary);
    result.imaginary = (n1.real * n2.imaginary) + (n1.imaginary * n2.real);
    return  result;
}

ComplexNum complex_divide(ComplexNum n1, ComplexNum n2) {
    ComplexNum result;

    //
    // Calculate the denominator: (c^2 + d^2)
    //
    float denominator = (n2.real * n2.real) + (n2.imaginary * n2.imaginary);

    //
    // Prevent crashing on division by zero
    //
    if (denominator == 0.0f) {
        printf("Error: Division by zero\n");
        result.real = 0;
        result.imaginary = 0;
        return result;
    }

    //
    // Apply the mathematical formula components
    //
    result.real =
        ((n1.real * n2.real) + (n1.imaginary * n2.imaginary)) / denominator;
    result.imaginary =
        ((n1.imaginary * n2.real) - (n1.real * n2.imaginary)) / denominator;

    return result;
}

void complex_display(ComplexNum num) {
    printf("Result: %.2d+%.2di\n", num.real, num.imaginary);
}

int main() {
    ComplexNum n1 = { 4, 5 };
    ComplexNum n2 = { 2, 3 };

    complex_display(complex_add(n1, n2));
    complex_display(complex_subtract(n1, n2));
    complex_display(complex_multiply(n1, n2));
    complex_display(complex_divide(n1, n2));

    return 0;
}
