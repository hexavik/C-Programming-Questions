/**
 * @file positive_negative_rearranger.c
 *
 * @author Vikrant A. P. (vikrant_ap@hotmail.com)
 *
 * @date 2025-01-21
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void rearrange_elements(int arr[], int arr_len) {
    //
    // The initial step is to spearate out positive and negative 
    // elements in two different arrays and then pick one by one from
    // them in the original array.
    // 
    int positive_count = 0;
    int negative_count = 0;
    int * positive_arr;
    int * negative_arr;

    positive_arr = (int * )malloc(arr_len * sizeof(int));
    negative_arr = (int * )malloc(arr_len * sizeof(int));

    for (int i = 0; i < arr_len; ++i) {
        if (arr[i] > 0) {
            positive_arr[positive_count++] = arr[i];
        } else {
            negative_arr[negative_count++] = arr[i];
        }
    }

    // Display both arrays
    printf("pos arr: ");
    for (int i = 0; i < positive_count; ++i) {
        printf("%d, ", positive_arr[i]);
    }
    printf("\nneg arr");
    for (int i = 0; i < negative_count; ++i) {
        printf("%d, ", negative_arr[i]);
    }
    printf("\n");

    int pos_counter = 0;
    int neg_counter = 0;

    // Put the re-arranged numbers back to the original array
    for (int i = 0; i < arr_len; ++i) {
        if (pos_counter == positive_count) {
            arr[i] = negative_arr[neg_counter++];
            continue;
        }
        if (neg_counter == negative_count) {
            arr[i] = positive_arr[pos_counter++];
            continue;
        }

        arr[i] = i % 2 ?
        negative_arr[neg_counter++] :
        positive_arr[pos_counter++];
    }

    // Keep all positives at left
    /*for (int i = 0; i < arr_len; ++i) {
        if (!positive_count) {
            break;
        }
        if (arr[i] > 0) {
            // Swap positive number until it has negative number on the left
            while (arr[i - 1] < 0 && i != 0) {
                swap_elements(arr + i, arr + i - 1);
                i = i - 1;
            }
            positive_count--;
        }
    }*/

    free(positive_arr);
    free(negative_arr);
}

int main() {
    // Input array
    //int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    //int arr[] = {-1, 2, -3, 4, -5, 6};
    int arr[] = {-1, 2, -3, -4, -5, 6, -7, -8, -9};

    // Calculate the size of the array
    int arr_len = sizeof(arr) / sizeof(arr[0]);

    rearrange_elements(arr, arr_len);

    // Display output
    printf("Result: ");
    for (int i = 0; i < arr_len; ++i) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    return 0;
}
