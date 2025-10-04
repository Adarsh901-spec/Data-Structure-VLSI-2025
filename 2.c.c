#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("%d\n", sum);

    return 0;
}