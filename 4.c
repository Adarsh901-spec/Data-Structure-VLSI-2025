#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // Required for malloc and free

bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int)); // Allocate memory on the heap

    if (arr == NULL) { // Check if malloc was successful
        fprintf(stderr, "Memory allocation failed!\n");
        return 1; // Indicate an error
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isSorted(arr, n)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    free(arr); // Free the allocated memory

    return 0;
}