/**
 * @file divisble_sum_pairs_checker.c
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * @date 2023-12-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Swaps two number in an array at different indices.
 *
 * @param arr Input int array.
 * @param oldindex Current index the number at.
 * @param newindex Expected index the number need to be.
 */
void swap(int arr[], size_t oldindex, size_t newindex) {
    int temp = arr[oldindex];
    arr[oldindex] = arr[newindex];
    arr[newindex] = temp;
}

/**
 * @brief Determines whether the sums of the divisible pairs are
 * available in an array. Each number may only be used in one pair;
 * once a pair has already been formed, the numbers cannot be used in
 * another pair.
 *
 * @param arr Input int array.
 * @param len Length of the input array.
 * @param divisor The input non-zero and positive divisor number.
 * @return true If all paired numbers' sums are divisible by the divisor.
 * @return false If any pair's sum is not divisible by the divisor.
 */
bool are_all_pairs_divisible(int arr[], size_t len, int divisor) {
    // Validate the k is non-negative or non-zero
    if (divisor <= 0) {
        printf("ERROR: The input divisor is zero or a negative number.");
        return 0;
    }

    // Current index of the element from array to store as a first
    // number in a pair
    int curr_index = 0;
    // If pair found then this will be updated as true or remain false
    bool is_pair_divisible = false;

    while (1) {
        int num1 = arr[curr_index];
        // Reset to false to validate whether the new pair is
        // divisible or not
        is_pair_divisible = false;

        for (int i = curr_index + 1; i < len; ++i) {
            int x = (num1 + arr[i]) % divisor;
            if (x) {
                // Continue loop if the sum of pair is not divisible
                // by a divisor
                continue;
            }

            is_pair_divisible = true;
            // Swap the index of the current number found as a pair
            // with the number next to the first number in a pair
            swap(arr, i, curr_index + 1);
            curr_index += 2;
            break;
        }
        if (!is_pair_divisible) {
            break;
        }

        if (curr_index + 2 == len) {
            break;
        }
    }

    return is_pair_divisible;
}

int main() {
    int arr[] = {9, 7, 5, 6, -3, 6};

    // Calculate the length of array
    size_t len = sizeof(arr) / sizeof(int);

    // Validate the length is even
    if (len & 1) {
        printf("ERROR: The input array has odd length.");
        return 0;
    }

    // Take an input from user for k (divisor)
    int k = 0;
    printf("Enter the divisor: ");
    scanf("%d", &k);

    //
    // To determine whether or not the sum of the two numbers in the
    // input array is divisible by the input divisor, we will take the
    // first number for the pair and the next number. We will check
    // the next pair to see if the result is true, and if not, we will
    // go on to the next number in the array by increasing the current
    // index for the first number by two. We will exchange the number
    // with the number adjacent to the first number in the pair if the
    // pair is divisible by the divisor. We will return false,
    // indicating that none of the pairs are divisible by the divisor,
    // if we don't find a pair during the entire for loop execution.
    //

    are_all_pairs_divisible(arr, len, k)
        ? printf("result: True\n") : printf("result: False\n");

    return 0;
}
