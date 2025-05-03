/**
 * @file array_right_rotator.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2023-12-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stddef.h>
#include <stdio.h>

/**
 * @brief Shuffles element at start by element at end, till the mid of
 * start and end position.
 * e.g. [1, 2, 3] becomes [3, 2, 1]
 * e.g. [1, 2, 3, 4] becomes [4, 3, 2, 1]
 *
 * @param arr Input array
 * @param start Starting index / position
 * @param end Ending index / position
 */
void juggle(int arr[], size_t start, size_t end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Increament start position and decrement end position
        ++start;
        --end;
    }
}

/**
 * @brief Rotate array towards right by using junggling algorithm.
 *
 * @param arr Input array
 * @param arraylength Length of input array
 * @param steps How many places to rotate
 */
void rotate(int arr[], size_t arraylength, size_t steps) {
    // Juggle first set
    juggle(arr, 0, arraylength - steps - 1);
    // Juggle second set
    juggle(arr, arraylength - steps, arraylength - 1);
    // Reverse whole array
    juggle(arr, 0, arraylength - 1);
}

int main() {
    // Take a default array
    int arr[] = {1, 2, 3, 4, 5};

    // Calculate the length of array and display it
    size_t len = sizeof(arr) / sizeof(int);
    printf("Length of array: %zu\n", len);

    // Stores number of steps to rotate to right
    int k = 0;

    // Take an input from user for k
    printf("Enter how many stesp you want to rotate to right: ");
    scanf("%d", &k);

    // Validate the size of the array and the steps given
    if (k > len) {
        printf("The value of k is invalid (more than length of array)");
        return 0;
    }

    //
    // Approach 1: time complexity  O(n * k)
    //
    // We shall take one temp variable here in which last element of the
    // array will be stored. Then we push all the previous elements to the
    // next index. This will rorate array one step towards right, so we will
    // repeat this process k times.
    //
    /*for (int i = 0; i < k; ++i) {
        int temp = arr[len - 1];
        for (int j = len - 1; j > 0; --j) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }*/

    //
    // Approach 2: time complexity O(n)
    //
    // We shall use Juggling Algorithm here to rotate array by input steps.
    // First we split array into two sets and then juggle them one by one.
    // This will result into reversed output array, so we juggle once again
    // to bring out the actual result.
    // e.g. [1, 2, 3, 4, 5] rotate by 2
    // expected output: [4, 5, 1, 2, 3]
    // if you pay attention then we split array into two sets at the index
    // equals to step i.e. [1, 2, 3] and [4, 5]
    // After juggling these two sets we will get [3, 2, 1] and [5, 4]
    // which is [3, 2, 1, 5, 4]. After juggling the whole array as a set
    // will reverse all elements which is [4, 5, 1, 2, 3].
    //
    rotate(arr, len, k);

    // Dispaly result array
    printf("result: [");
    for (int i = 0; i < len; ++i) {
        printf("%d", arr[i]);
        if (i < len - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
