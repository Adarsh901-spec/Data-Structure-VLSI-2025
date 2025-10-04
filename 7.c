#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;


    scanf("%d %d", &rows, &cols);
    int matrix[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) {
                printf(" ");
            }
        }
        printf(" \n");
    }

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d", matrix[j][i]);
            if (j < rows - 1) {
                printf(" ");
            }
        }
        printf(" \n");
    }

    return 0;
}