/**
 * @file dynamic_array.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2025-02-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Inserts a specified element into an array at the last 
 * index position. This position automatically updates itself.
 * 
 * @param arr Input array
 * @param size Pointer to the size of the array
 * @param element Value to be added
 */
void insert(int * arr, int * size, int element) {
    (*size)++;

    if (*size != 1) {
        // Reallocate the memory
        arr = realloc(arr, (*size) * sizeof(arr[0]));
    }

    arr[*size - 1] = element;
}

/**
 * @brief Removes a specified element from an array in case if it
 * is availble. If found then array's size reduced by one place.
 * 
 * @param arr Input array
 * @param size Pointer to the size of the array
 * @param element Value to be removed
 */
void delete(int * arr, int * size, int element) {
    int i, j;
    for (i = 0; i < *size; ++i) {
        if (*(arr + i) == element) {
            break;
        }
    }

    // If the for loop reached to the size fo an array
    if (i == *size) {
        printf("Expected element not found.\n");
        return;
    }

    // Shift the next elements to the left
    for (int j = i; j < *size; ++j) {
        *(arr + j) = *(arr + j + 1);
    }

    // Update the size by decrementing it
    --(*size);

    // Reallocate the updated array to avoid memeory leak issues
    arr = (int * )realloc(arr, (*size) * sizeof(arr[0]));
    if (!arr) {
        printf("ERROR: Memory reallocation failed during deletion.\n");
        exit(1);
    }
}

/**
 * @brief Get the element at the specified index from an array.
 * 
 * @param arr Input array
 * @param index Poistion from which the element need to be retrieved
 * @return int The element present at the index in array
 */
int get_element(int * arr, int index) {
    return *(arr + index);
}

/**
 * @brief Display the array
 * 
 * @param arr Input array
 * @param size Pointer to the size of the array
 */
void display_array(int * arr, int * size) {
    printf("Arr: ");
    for (int i = 0; i < *size; ++i) {
        printf("%d, ", get_element(arr, i));
    }
    printf("\n");
}

int main() {
    int size = 0;
    int * arr = (int *)malloc((size + 1) * sizeof(int));

    insert(arr, &size, 5);
    insert(arr, &size, 10);
    insert(arr, &size, 15);
    insert(arr, &size, 20);

    // Display the array
    display_array(arr, &size);

    delete(arr, &size, 10);

    // Display the array
    display_array(arr, &size);

    // Release dynamically allocated memory
    free(arr);
    arr = NULL;

    return 0;
}
