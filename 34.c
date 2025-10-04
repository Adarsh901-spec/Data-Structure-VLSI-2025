#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Performs a linear search to find the first occurrence of a key in an array.
 *
 * @param arr The array to search in.
 * @param n The number of elements in the array.
 * @param key The element to search for.
 * @return The index of the first occurrence of the key, or -1 if not found.
 */
int linear_search(int arr[], int n, int key) {
    // Iterate through the array from the beginning.
    for (int i = 0; i < n; i++) {
        // If the current element matches the key, we've found the first occurrence.
        if (arr[i] == key) {
            return i; // Return the index immediately.
        }
    }
    // If the loop completes, the key was not found.
    return -1;
}

int main() {
    int n;
    
    // Read the number of elements in the array.
    scanf("%d", &n);
    
    // Dynamically allocate memory for the array.
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        // Handle memory allocation failure.
        return 1;
    }
    
    // Read the elements of the array.
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int key;
    // Read the key element to be searched.
    scanf("%d", &key);
    
    // Perform the search.
    int result_index = linear_search(arr, n, key);
    
    // Print the result based on whether the element was found.
    if (result_index != -1) {
        printf("%d\n", result_index);
    } else {
        printf("Not found\n");
    }
    
    // Free the dynamically allocated memory.
    free(arr);
    
    return 0;
}
