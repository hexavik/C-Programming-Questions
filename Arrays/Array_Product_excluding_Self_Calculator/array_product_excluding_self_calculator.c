/**
 * @file array_product_excluding_self_calculator.c
 * 
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * 
 * @date 2023-12-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4};
    
    // Calculate the size of array
    int len = sizeof(arr) / sizeof(int);

    // The result array
    int result[len];

    //
    // We shall follow two pass approach here. In the first pass we shall
    // calculate the product of all elements to the left of each element 
    // (excluding itself). In the second pass, iterate from the right side 
    // and multiply each element by the product calculated in the first 
    // pass.
    //

    int leftProd = 1;
    int rightProd = 1;

    // First pass: calculate left product
    for (int i = 0; i < len; ++i) {
        result[i] = leftProd;
        leftProd *= arr[i];
    }

    // Second pass: multiply by right product
    for (int i = len - 1; i >= 0; --i) {
        result[i] *= rightProd;
        rightProd *= arr[i];
    }

    // Display result array
    printf("result: ");
    for (int i = 0; i < len; ++i) {
        printf("%d, ", result[i]);
    }

    return 0;
}
