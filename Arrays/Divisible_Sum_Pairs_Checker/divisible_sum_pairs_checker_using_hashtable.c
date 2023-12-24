/**
 * @file divisible_sum_pairs_checker_using_hashmaps.c
 * 
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 * 
 * @date 2023-12-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Determines whether the sums of the divisible pairs are available 
 * in an array. Each number may only be used in one pair; once a pair has 
 * already been formed, the numbers cannot be used in another pair.
 * 
 * @param arr Input int array.
 * @param len Length of the input array.
 * @param divisor The input non-zero and positive divisor number.
 * @return true If all paired numbers' sums are divisible by the divisor.
 * @return false If any pair's sum is not divisible by the divisor.
 */
bool areAllPairsDivisible(int arr[], int len, int divisor) {
    // Validate the k is non-negative or non-zero
    if (divisor <= 0) {
        printf("ERROR: The input divisor is zero or a negative number.");
        return 0;
    }

    // Use a hash table to efficiently track potential pair elements
    int freq[100] = {0};    // Assuming k is less than 100

    // Iterate through the array and update frequencies
    for (int i = 0; i < len; ++i) {
        // Calculate remainder for each number in an input array
        // and handle negative remainders
        int remainder = (arr[i] % divisor + divisor) % divisor;
        freq[remainder]++;
    }

    // Check if each element has a matching pair
    for (int i = 1; i < divisor; ++i) {
        if (freq[i] != freq[divisor - i]) {
            return false;
        }
    }

    // All pairs are divisible
    return true;
}

int main() {
    // Input array
    int arr[] = {9, 7, 5, 6, -3, 6};

    // Calculate the length of array
    int len = sizeof(arr) / sizeof(int);

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
    // We will use an array as a hash table. For the hahs table, we will 
    // create a fixed-size array that we will only use up to the divisor 
    // value. When array items are divided by k (the divisor), the 
    // frequencies of remainders will be stored. Pair checking is made 
    // possible in this way. We shall handle negative remainders by 
    // computing the residual of each element when divided by k. The 
    // remainder is used as an index value and the freq value at that index
    // will be incremented. Lastly, we shall determine whether or not a 
    // rermainder's frequency (i and k - i) equals that of its 
    // complementary remainder. If not, it returns false because there 
    // isn't a matching pair.
    //

    areAllPairsDivisible(arr, len, k) 
        ? printf("result: True\n") : printf("result: False\n");

    return 0;
}
