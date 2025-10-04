#include <stdio.h>
#include <stdlib.h> // For dynamic memory allocation

int main() {
    int r, c;

    // Read number of rows and columns
    scanf("%d %d", &r, &c);

    // Dynamically allocate memory for the 2D array
    int **arr = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++) {
        arr[i] = (int *)malloc(c * sizeof(int));
    }

    // Read elements to populate the 2D array
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Print in row-major order
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Print in column-major order
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < r; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}