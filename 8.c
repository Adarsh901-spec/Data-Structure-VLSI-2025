#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int zero_count = 0;
    int nonzero_count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zero_count++;
            } else {
                nonzero_count++;
            }
        }
    }

    bool is_sparse = (zero_count > nonzero_count);
    printf("%s\n", is_sparse ? "True" : "False");

    if (is_sparse) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] != 0) {
                    printf("%d %d %d\n", i, j, matrix[i][j]);
                }
            }
        }
    }

    return 0;
}