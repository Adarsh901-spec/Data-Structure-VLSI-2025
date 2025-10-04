#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, target;

    // Read the size of the array
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Read the elements of the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the target element to search for
    scanf("%d", &target);

    // Count the occurrences of the target element
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            count++;
        }
    }

    // Print the count
    printf("%d\n", count);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}