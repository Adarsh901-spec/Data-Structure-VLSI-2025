#include <stdio.h>

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    int zero_count = 0;
    int non_zero_count = 0;

    // Read matrix and count zeros/non-zeros
    for (int i=0; i < rows; i++) {
        for (int j=0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0)
                zero_count++;
            else
                non_zero_count++;
        }
    }

    int total_elements = rows * cols;

    // Print triplet if sparse and has at least one non-zero
    if (zero_count > total_elements / 2 && non_zero_count > 0) {
        for (int i=0; i < rows; i++) {
            for (int j=0; j < cols; j++) {
                if (matrix[i][j] != 0) {
                    printf("%d %d %d\n", i, j, matrix[i][j]);
                }
            }
        }
    } else {
        printf("-1\n");
    }

    return 0;
}